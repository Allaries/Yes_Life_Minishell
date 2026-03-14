/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:46 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/14 05:14:46 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int g_sig_status;

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_data	data;
	int i = 2;

	if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO))
		exit (0);
	
	if (argc && argv) // Pour aucun warning
		argc = 1;
	data.envp = dupe_env(envp);
	data.exit_code = 0;
	change_signal(&data);
	while (i)
	{
		g_sig_status = 0;
		change_signal(&data);
		input = readline("mini-0.7.10$ ");
		if (!input) //Ctrl-D
		{
			free_tab(data.envp);
			printf("exit\n");
			return (1);
		}
		if (input && *input)
			add_history(input);
		parsing(input, &data);
		free(input);
		input = NULL;
	}
	free_tab(data.envp);
	return (0);
}

// to compile : valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ./minishell
