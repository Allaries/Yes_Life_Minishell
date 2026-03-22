/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calling_bi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 01:36:53 by rerichar          #+#    #+#             */
/*   Updated: 2026/03/20 19:28:04 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exec_single_bi(int mod, t_data *data, t_cmd *cmd)
{
	if (mod == 6)
		bi_exit(data, cmd);
	data->exit_code = 0;
	if (mod == 1)
		bi_echo(cmd);
	if (mod == 2)
	{
		data->exit_code = bi_cd(cmd->args, data->envp);
		change_pwd(data);
	}
	if (mod == 3)
		data->exit_code = bi_pwd(cmd);
	if (mod == 4)
		data->exit_code = bi_export(data, cmd);
	if (mod == 5)
		data->exit_code = bi_unset(data, cmd);
	if (mod == 7)
		bi_env(data, cmd);
	return ;
}

void	check_bi(t_cmd *cmd)
{
	if (!cmd->args)
		return ;
	if (ft_strncmp(cmd->args[0], "echo", 5) == 0)
		cmd->built_in = 1;
	else if (ft_strncmp(cmd->args[0], "cd", 3) == 0)
		cmd->built_in = 2;
	else if (ft_strncmp(cmd->args[0], "pwd", 4) == 0)
		cmd->built_in = 3;
	else if (ft_strncmp(cmd->args[0], "export", 7) == 0)
		cmd->built_in = 4;
	else if (ft_strncmp(cmd->args[0], "unset", 6) == 0)
		cmd->built_in = 5;
	else if (ft_strncmp(cmd->args[0], "exit", 5) == 0)
		cmd->built_in = 6;
	else if (ft_strncmp(cmd->args[0], "env", 4) == 0)
		cmd->built_in = 7;
	else
		cmd->built_in = 0;
	return ;
}
