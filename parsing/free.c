/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/07 01:20:22 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_all(t_token **list, t_word **word)
{
	if (list && *list)
		free_list_token(list);
	if (word && *word)
		free_word(word);
}

void	free_list_token(t_token **list)
{
	t_token	*tmp;
	t_token	*next;

	tmp = NULL;
	next = NULL;
	if ((!list || !*list))
		return ;
	tmp = *list;
	while (tmp)
	{
		next = tmp->next;
		free_token(tmp);
		tmp = next;
	}
	*list = NULL;
}

void	free_list_cmd(t_cmd **list)
{
	t_cmd	*tmp;
	t_cmd	*next;

	tmp = NULL;
	next = NULL;
	if ((!list || !*list))
		return ;
	tmp = *list;
	while (tmp)
	{
		next = tmp->next;
		free_cmd(tmp);
		tmp = next;
	}
	*list = NULL;
}

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
	free_list_redir(cmd->redirs);
	free(cmd);
}

void	free_list_redir(t_redir **list)
{
	t_redir	*tmp;
	t_redir	*next;

	tmp = NULL;
	next = NULL;
	if ((!list || !*list))
		return ;
	tmp = *list;
	while (tmp)
	{
		next = tmp->next;
		free_redir(tmp);
		tmp = next;
	}
	*list = NULL;
}

void	free_redir(t_redir *redir)
{
	if (!redir)
		return ;
	free(redir->name);
	free(redir);
}
