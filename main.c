/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:46 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/13 02:59:41 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_data	data;
	int		i;

	if (argc && argv) // Pour aucun warning
		argc = 1;
	i = 3;
	data.envp = dupe_env(envp);
	while (i--) // i pour tester valgrind
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
