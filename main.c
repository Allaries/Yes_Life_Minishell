/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:46 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/20 19:49:33 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_sig_status;

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_data	data;

	(void)argc;
	(void)argv;
	data.envp = dupe_env(envp);
	data.exit_code = 0;
	change_signal(&data, 0);
	while (1)
	{
		g_sig_status = 0;
		change_signal(&data, 0);
		if (isatty(STDIN_FILENO))
			input = readline("mini-0.7.10$ ");
		else
			input = readline("");
		if (!input)
		{
			free_tab(data.envp);
			exit(data.exit_code);
		}
		if (input && *input)
			add_history(input);
		parsing(input, &data);
		free(input);
		input = NULL;
	}
	free_tab(data.envp);
	exit(data.exit_code);
}