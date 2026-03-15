/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 22:48:06 by rerichar          #+#    #+#             */
/*   Updated: 2026/03/15 22:02:24 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	sigint_handler_readline(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
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

void	change_signal(t_data *data)
{
	if (g_sig_status == 0)
	{
		set_term_signal(data);
	}
	if (g_sig_status == 1)
	{
		signal (SIGINT, SIG_DFL);
		signal (SIGQUIT, SIG_IGN);
	}
	if (g_sig_status == 2)
	{
		signal (SIGINT, SIG_DFL);
		signal (SIGQUIT, SIG_DFL);
	}
	if (g_sig_status == 3)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}
