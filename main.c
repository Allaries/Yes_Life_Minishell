/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remi <remi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:46 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/22 19:09:26 by remi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_sig_status;

void	terminal(t_data *data)
{
	char	*input;

	g_sig_status = 0;
	change_signal(data, 0);
	if (isatty(STDIN_FILENO))
		input = readline("mini-0.7.10$ ");
	else
		input = readline("");
	if (!input)
	{
		free_tab(data->envp);
		exit(data->exit_code);
	}
	if (input && *input)
		add_history(input);
	parsing(input, data);
	free(input);
	input = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argc;
	(void)argv;
	data.envp = dupe_env(envp);
	data.exit_code = 0;
	while (1)
		terminal(&data);
	free_tab(data.envp);
	exit(data.exit_code);
}
