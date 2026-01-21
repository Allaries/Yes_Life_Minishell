/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calling_bi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 01:36:53 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/21 17:13:55 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_single_bi(int mod, char **envp, t_cmd *cmd)
{
	if (mod == 1)
		bi_echo(cmd->args);
	if (mod == 2)
		bi_cd(cmd->args, envp);
	if (mod == 3)
		bi_pwd();
	if (mod == 4)
		bi_export(cmd->args, envp);
	if (mod == 5)
		bi_unset(cmd->args, envp);
	if (mod == 6)
		bi_exit();
	return ;
}

int	check_bi(char **cmd)
{
	if (strncmp(cmd[0], "echo", 5) == 0)
		return (1);
	if (strncmp(cmd[0], "cd", 3) == 0)
		return (2);
	if (strncmp(cmd[0], "pwd", 4) == 0)
		return (3);
	if (strncmp(cmd[0], "export", 7) == 0)
		return (4);
	if (strncmp(cmd[0], "unset", 6) == 0)
		return (5);
	if (strncmp(cmd[0], "exit", 5) == 0)
		return (6);
	return (0);
}