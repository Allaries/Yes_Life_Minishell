/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_util1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 14:16:53 by rerichar          #+#    #+#             */
/*   Updated: 2026/03/20 19:28:04 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void	adv_pipe(t_data *data)
{
	data->oldpipe[0] = data->newpipe[0];
	data->oldpipe[1] = data->newpipe[1];
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
