/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:46 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/21 16:25:12 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_data	data;
	int i = 2;

	if (argc && argv) // Pour aucun warning
		argc = 1;
	data.envp = dupe_env(envp);
	//SARAH
	//JE VAIS ETRE CLAIR
	//TU RAJOUTE UN -- A CE I, IL VA Y AVOIR DES BRICOLES
	//cordialement, ton mate minishell
	while (i)
	{
		input = readline("mini-0.1$ ");
		if (!input)
		{
			perror("Error");
			return (1);
		}
		parsing(input, &data);
		free(input);
		input = NULL;
	}
	free_tab(data.envp);
	return (0);
}

// to compile : valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ./minishell
