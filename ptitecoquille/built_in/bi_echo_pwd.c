/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:51:36 by rerichar          #+#    #+#             */
/*   Updated: 2026/02/14 02:32:00 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	bi_pwd(void)
{
	char	*pwd;
	
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		exit(1);
	}
	printf("%s\n", pwd);
	free (pwd);
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

void	bi_echo(char **cmd)
{
	int	i;
	int	n;

	i = 1;
	if (cmd[1])
		n = echo_flag_test(cmd[i]);
	if (n == 1)
		i++;
	while (cmd[i])
	{
		printf("%s", cmd[i]);
		i++;
		if (cmd[i])
			printf(" ");
	}
	if (n == 1)
		return ;
	printf ("\n");
}
