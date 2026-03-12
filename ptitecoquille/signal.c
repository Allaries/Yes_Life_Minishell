/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 22:48:06 by rerichar          #+#    #+#             */
/*   Updated: 2026/03/12 22:54:36 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_signal(t_data *data)
{
	if (g_sig_status == 0)
	{
		//minishell = bash (Ctrl -C = retour a la ligne, Ctrl -D = exit Ctrl -\ = rien)
		//on l'a dans le main
	}
	if (g_sig_status == 1)
	{
		//fork (commande ou heredoc), Ctrl -C segv, Ctrl -D exit le Child et Ctrl -\ toujours un clown
		//on l'a dans les heredoc / child.c
	}
	if (g_sig_status == 2)
	{
		//zombie vegetatif tarpin guez, quand le parent attend un enfant qu'il finisse sa tache
		//aucun signaux marchent, juste on attend la fin du child (waitpid tu connait)
	}
}