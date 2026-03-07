/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:46 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/07 16:48:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void sigint_handler_readline(int sig)
{
    (void)sig;
    write(1, "\n", 1);
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

// static void sigint_handler_child(int sig)


int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_data	data;
	int i = 2;

	if (argc && argv) // Pour aucun warning
		argc = 1;
	data.envp = dupe_env(envp);
    data.sa.sa_handler = sigint_handler_readline;
    sigemptyset(&data.sa.sa_mask);
    data.sa.sa_flags = 0;
    sigaction(SIGINT, &data.sa, NULL);
	//SARAH
	//JE VAIS ETRE CLAIR
	//TU RAJOUTE UN -- A CE I, IL VA Y AVOIR DES BRICOLES
	//cordialement, le R
	//hahhaha ok vu que le ctrl-C est geré je le fait pas t'as de la chance, la S
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
