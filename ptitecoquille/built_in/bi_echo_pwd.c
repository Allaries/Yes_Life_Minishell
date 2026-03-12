/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:51:36 by rerichar          #+#    #+#             */
/*   Updated: 2026/03/12 19:03:04 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	bi_pwd(t_cmd *cmd)
{
	char	*pwd;
	
	pwd = getcwd(NULL, 0);
	if (!pwd || pwd == NULL)
	{
		write(cmd->infd, "welcome to the shadow realm\n", 28);
		return (1);
	}
	write(cmd->infd, pwd, ft_strlen(pwd));
	write(cmd->infd, "\n", 1);
	free (pwd);
	return (0);
}

int	echo_flag_test(char *cmd)
{
	int	i;

	i = 0;
	if (cmd[i] == '-')
	{
		i++;
		while (cmd[i])
		{
			if (cmd[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	bi_echo(t_cmd *cmd)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	if (cmd->args[1])
		n = echo_flag_test(cmd->args[i]);
	if (n == 1)
		i++;
	while (cmd->args[i])
	{
		write(cmd->outfd, cmd->args[i], ft_strlen(cmd->args[i]));
		i++;
		if (cmd->args[i])
			write(cmd->outfd, " ", 1);
	}
	if (n == 0)
		write(cmd->outfd, "\n", 1);
	return ;
}
