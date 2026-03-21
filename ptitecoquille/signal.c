/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 22:48:06 by rerichar          #+#    #+#             */
/*   Updated: 2026/03/20 18:42:22 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	sigint_handler_readline(int sig)
{
	(void)sig;
	rl_done = 0;
	g_sig_status = SIGINT;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handler_heredoc(int sig)
{
	(void)sig;
	g_sig_status = SIGINT;
	write (1, "\n", 1);
	close (0);
	rl_replace_line("", 0);
	rl_on_new_line();
}

void	set_term_signal(t_data *data)
{
	data->sa.sa_handler = sigint_handler_readline;
	sigemptyset(&data->sa.sa_mask);
	data->sa.sa_flags = 0;
	sigaction(SIGINT, &data->sa, NULL);
	data->sq.sa_handler = SIG_IGN;
	sigemptyset(&data->sq.sa_mask);
	data->sq.sa_flags = 0;
	sigaction(SIGQUIT, &data->sq, NULL);
}

void	change_signal(t_data *data, int type)
{
	if (type == 0)
	{
		set_term_signal(data);
	}
	if (type == 1)
	{
		data->sa.sa_handler = handler_heredoc;
		sigemptyset(&data->sa.sa_mask);
		data->sa.sa_flags = 0;
		sigaction(SIGINT, &data->sa, NULL);
		signal(SIGQUIT, SIG_IGN);
	}
	if (type == 2)
	{
		signal (SIGINT, SIG_DFL);
		signal (SIGQUIT, SIG_IGN);
	}
	if (type == 3)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}
