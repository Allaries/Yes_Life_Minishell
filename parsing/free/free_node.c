/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 05:05:38 by rerichar          #+#    #+#             */
/*   Updated: 2026/02/16 06:39:13 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_token(t_token *tok)
{
	if (!tok)
		return ;
	free(tok->word);
	free(tok);
}

void	free_word(t_word **word)
{
	if (!word || !*word)
		return ;
	free((*word)->buf);
	free(*word);
	*word = NULL;
}

void	free_input(t_input **new_input)
{
	if (!new_input || !*new_input)
		return ;
	free((*new_input)->str);
	free(*new_input);
	*new_input = NULL;
}

void	free_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		return ;
	if (cmd->args)
	{
		i = 0;
		while (cmd->args[i])
			free(cmd->args[i++]);
		free(cmd->args);
	}
	free_list_redir(&cmd->redirs);
	free(cmd);
}


void	free_redir(t_redir *redir)
{
	if (!redir)
		return ;
	free(redir->name);
	free(redir);
}
