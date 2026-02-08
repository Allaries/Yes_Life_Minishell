/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 01:36:53 by rerichar          #+#    #+#             */
/*   Updated: 2026/02/08 19:07:59 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	close_all(t_data *data, t_cmd *cmd)
{
	close(data->oldpipe[0]);
	close(data->oldpipe[1]);
	close(data->newpipe[0]);
	close(data->newpipe[1]);
	if (cmd->infd != 0)
		close(cmd->infd);
	if (cmd->outfd != 1)
		close(cmd->outfd);
	return (1);
}


void	close_daddy_prime(t_data *data, t_cmd *cmd, int i)
{
	if (i == 0)
	{
		if (cmd->infd != 0)
			close (cmd->infd);
		close (data->newpipe[1]);
	}
	else if (cmd->next == NULL)
		close_all(data, cmd);
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

int	execute_child(t_data *data, t_cmd *cmd, int i)
{
	cmd->pid = fork();
	if (cmd->pid != 0)
		return (1);
	def_path(data, cmd);
	if (cmd->built_in != 0)
	{
		exec_single_bi(cmd->built_in, data, cmd);
		thanos_snap_process(data);
		exit(0);
	}
	if (cmd->path == NULL && cmd->built_in == 0)
	{
		printf ("command not found: %s", cmd->args[0]);
		close_all(data, cmd);
		exit(127);
	}
	dup2_child_hack(data, cmd, i);
	if (i != 0 && close_all(data, cmd) == 0)
	{
		fprintf(stderr, "close error at i = %i\n", i);
		exit(127);
	}
	if (execve(cmd->path, cmd->args, data->envp) == -1)
		perror("Error ");
	exit(127);
}

void	adv_pipe(t_data *data)
{
	data->oldpipe[0] = data->newpipe[0];
	data->oldpipe[1] = data->newpipe[1];
}

void	exec_only_one(t_cmd *cmd, t_data *data)
{
	if (cmd->built_in != 0)
		exec_single_bi(cmd->built_in, data, cmd);
	else
		execute_child(data, cmd, 0);
	return ;
}

int	exec_pipex(t_data *data, t_cmd **cmd)
{
	int		i;
	int		status;
	t_cmd	*here_cmd;

	i = 0;
	here_cmd = *cmd;
	// init_heredoc(cmd);
	if (here_cmd->next == NULL)
	{
		get_fd(here_cmd);
		check_bi(here_cmd);
		exec_only_one(here_cmd, data);
		return (1);
	}
	while (here_cmd)
	{
		get_fd(here_cmd);
		check_bi(here_cmd);
		if (here_cmd->next != NULL)
			pipe(data->newpipe);
		execute_child(data, here_cmd, i);
		close_daddy_prime(data, here_cmd, i);
		adv_pipe(data);
		here_cmd = here_cmd->next;
		i++;
	}
	here_cmd = *cmd;
	while (here_cmd)
	{
		waitpid(here_cmd->pid, &status, 0);
		here_cmd = here_cmd ->next;
	}
	return (1);
}
