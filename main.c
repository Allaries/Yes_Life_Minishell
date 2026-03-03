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

// static void sigint_handler(int sig)
// {
//     (void)sig;
//     write(1, "\n", 1);
//     rl_on_new_line();
//     rl_replace_line("", 0);
//     rl_redisplay();
// }

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	// struct	sigaction sa;
	t_data	data;
	int i = 2;

	if (argc && argv) // Pour aucun warning
		argc = 1;
	data.envp = dupe_env(envp);
    // sa.sa_handler = sigint_handler;
    // sigemptyset(&sa.sa_mask);
    // sa.sa_flags = 0;
    // sigaction(SIGINT, &sa, NULL);
	//SARAH
	//JE VAIS ETRE CLAIR
	//TU RAJOUTE UN -- A CE I, IL VA Y AVOIR DES BRICOLES
	//cordialement, le R
	while (i)
	{
		input = readline("mini-0.1$ ");
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
