/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calling_bi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 01:36:53 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/07 15:40:23 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"






int	main(int ac, char **av, char** envp)
{
	char	**cpenv;

	cpenv = dupe_env(envp);
	int	i = 0;
	while (cpenv[i])
	{
		printf("%s\n", cpenv[i]);
		i++;
	}
	// char *cmd[4];

	// cmd[0] = "cat";
	// cmd[1] = "-n";
	// cmd[2] = "my fellas";
	// cmd[3] = NULL;
	
}