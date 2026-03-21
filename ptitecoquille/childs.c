/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 01:36:53 by rerichar          #+#    #+#             */
/*   Updated: 2026/03/20 19:43:38 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	wait_cmd(t_data *data, t_cmd *cmd)
{
	int		status;
	int		good;

	good = 0;
	while (cmd)
	{
		waitpid(cmd->pid, &status, 0);
		data->exit_code = WEXITSTATUS(status);
		cmd = cmd ->next;
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
		{
			// fprintf(stderr, "gougougaga");
			if (good == 0)
				write(2, "Core dumped\n", 1);
			good++;
			data->exit_code = 131;
		}
	}
}

int	close_all(t_data *data, t_cmd *cmd, int i)
{
	if (cmd->single_one == 0)
	{
		if (i != 0)
		{
			close(data->oldpipe[0]);
			close(data->oldpipe[1]);
		}
		close(data->newpipe[0]);
		close(data->newpipe[1]);
	}
	if (cmd->infd > 1)
		close(cmd->infd);
	if (cmd->outfd > 1)
		close(cmd->outfd);
	return (1);
}

void	close_daddy_prime(t_data *data, t_cmd *cmd, int i)
{
	if (i == 0)
	{
		if (cmd->infd > 1)
			close (cmd->infd);
		close (data->newpipe[1]);
	}
	else if (cmd->next == NULL)
		close_all(data, cmd, i);
	else
	{
		close(data->oldpipe[0]);
		close(data->newpipe[1]);
	}
}

void	dup2_infile_hack(t_data *data, t_cmd *cmd, int i)
{
	if (i == 0)
	{
		if (cmd->infd != STDIN_FILENO)
			dup2(cmd->infd, STDIN_FILENO);
	}
	else
	{
		if (cmd->infd != STDIN_FILENO)
		{
			dup2(cmd->infd, STDIN_FILENO);
		}
		else
			dup2(data->oldpipe[0], STDIN_FILENO);
	}
	return ;
}

void	dup2_outfile_hack(t_data *data, t_cmd *cmd)
{
	if (cmd->next == NULL)
	{
		if (cmd->outfd != 1)
			dup2(cmd->outfd, 1);
	}
	else
	{
		if (cmd->outfd != 1)
			dup2(cmd->outfd, 1);
		else
			dup2(data->newpipe[1], 1);
	}
}

void	dup2_child_hack(t_data *data, t_cmd *cmd, int i)
{
	dup2_infile_hack(data, cmd, i);
	dup2_outfile_hack(data, cmd);
	return ;
}

void	print_stderr(char *toprint, int mod)
{
	if (mod == 1)
		write (2, "command not found : ", 21);
	if (mod == 2)
		write (2, "cd : no such file or directory : ", 33);
	write (2, toprint, (ft_strlen(toprint) + 1));
	write (2, "\n", 1);
}

void	close_exec(t_data *data, t_cmd *cmd, int i, int y)
{
	close_other_here(data);
	close_all(data, cmd, i);
	thanos_snap_process(data);
	if (!y)
		exit(127);
	if (y)
		exit(data->exit_code);
}

int	execute_child(t_data *data, t_cmd *cmd, int i)
{
	cmd->pid = fork();
	if (cmd->pid != 0)
		return (1);
	change_signal(data, 2);
	if (cmd->args == NULL)
		close_exec(data, cmd, i, 0);
	if (def_path(data, cmd) == 0)
		cmd->path = NULL;
	if (cmd->built_in != 0)
	{
		cmd->poubelle = i;
		dup2_child_hack(data, cmd, i);
		exec_single_bi(cmd->built_in, data, cmd);
		close_exec(data, cmd, i, 1);
	}
	if (cmd->path == NULL)
	{
		print_stderr (cmd->args[0], 1);
		close_exec(data, cmd, i, 0);
	}
	dup2_child_hack(data, cmd, i);
	close_all(data, cmd, i);
	close_other_here(data);
	if (execve(cmd->path, cmd->args, data->envp) == -1)
		perror("Error ");
	thanos_snap_process(data);
	exit(127);
}

void	adv_pipe(t_data *data)
{
	data->oldpipe[0] = data->newpipe[0];
	data->oldpipe[1] = data->newpipe[1];
}

int	one_cmd(t_data *data, t_cmd *cmd)
{
	cmd->single_one = 1;
	if (get_fd(cmd) == 0)
		return (free_cmd_struct(data->cmd), 0);
	if (!cmd->args)
		return (free_cmd_struct(data->cmd), 1);
	check_bi(cmd);
	if (cmd->built_in != 0)
	exec_single_bi(cmd->built_in, data, cmd);
	else
	{
		execute_child(data, cmd, 0);
		wait_cmd(data, cmd);
	}
	free_cmd_struct(data->cmd);
	return (1);
}

int	pipeline(t_data *data, t_cmd *cmd, int i)
{
	cmd->single_one = 0;
	if (get_fd(cmd) == 0)
		return (free_cmd_struct(data->cmd), -1);
	check_bi(cmd);
	if (cmd->next != NULL)
		pipe(data->newpipe);
	execute_child(data, cmd, i);
	close_daddy_prime(data, cmd, i);
	adv_pipe(data);
	return (1);
}

int	exec_pipex(t_data *data, t_cmd **cmd)
{
	int		i;
	t_cmd	*here_cmd;

	i = 0;
	here_cmd = *cmd;
	if (!first_h_init(data, cmd))
		return(free_cmd_struct(data->cmd), 1);
	change_signal(data, 3);
	if (here_cmd->next == NULL)
		return (one_cmd(data, here_cmd), 1);
	here_cmd->single_one = 0;
	while (here_cmd)
	{
		if (pipeline(data, here_cmd, i) == -1)
			return (0);
		here_cmd = here_cmd->next;
		i++;
	}
	here_cmd = *cmd;
	wait_cmd(data, here_cmd);
	free_cmd_struct(data->cmd);
	return (1);
}
