/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/10 14:24:03 by rerichar         ###   ########.fr       */
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

void	free_list_redir(t_redir *list)
{
	t_redir	*tmp;
	t_redir	*next;

	tmp = NULL;
	next = NULL;
	if (!list)
		return ;
	tmp = list;
	while (tmp)
	{
		next = tmp->next;
		free_redir(tmp);
		tmp = next;
	}
	list = NULL;
}
