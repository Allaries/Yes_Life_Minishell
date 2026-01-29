/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/29 18:23:55 by smedenec         ###   ########.fr       */
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

void	free_token(t_token *tok)
{
	if (!tok)
		return ;
	free(tok->word);
	free(tok->qmask);
	free(tok);
}

void	free_word(t_word **word)
{
	if (!word || !*word)
		return ;
	free((*word)->buf);
	free((*word)->qmask);
	free(*word);
	*word = NULL;
}
