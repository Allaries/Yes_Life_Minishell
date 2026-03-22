/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remi <remi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 01:36:53 by rerichar          #+#    #+#             */
/*   Updated: 2026/03/22 18:05:36 by remi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

int	execute_child(t_data *data, t_cmd *cmd, int i)
{
	cmd->pid = fork();
	if (cmd->pid != 0)
		return (1);
	change_signal(data, 2);
	if (cmd->args == NULL)
		close_exec(data, cmd, i, 0);
	if (cmd->built_in != 0)
	{
		cmd->poubelle = i;
		dup2_child_hack(data, cmd, i);
		exec_single_bi(cmd->built_in, data, cmd);
		close_exec(data, cmd, i, 1);
	}
	if (def_path(data, cmd) == 0)
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
		return (free_cmd_struct(data->cmd), 1);
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
