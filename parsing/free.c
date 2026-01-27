/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/27 18:44:17 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_all(t_token **list, char **word)
{
	free_list_token(list);
	free_word(word);
}

void	free_list_token(t_token **list)
{
	t_token	*tmp;
	t_token	*next;

	tmp = NULL;
	next = NULL;
	if (list && *list)
	{
		tmp = *list;
		while (tmp)
		{
			next = tmp->next;
			free(tmp->word);
			free(tmp->qmask);
			free(tmp);
			tmp = next;
		}
		*list = NULL;
	}
}

void	free_word(t_word **word)
{
	if (word && *word)
	{
		free((*word)->buf);
		free((*word)->qmask);
		free(*word);
		*word = NULL;
	}
}
