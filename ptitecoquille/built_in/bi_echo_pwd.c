/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:51:36 by rerichar          #+#    #+#             */
/*   Updated: 2026/02/07 04:21:25 by rerichar         ###   ########.fr       */
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

void	bi_echo(char **cmd)
{
	//a ajuster apres que je sache comment les token ca marche
	if (strncmp(cmd[1], "-n", 3) == 0)
		printf("%s%%", cmd[2]);
	else
		printf("%s\n", cmd[1]);
}
