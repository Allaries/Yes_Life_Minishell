/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/22 14:57:42 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_list_word(t_token **list, char **word)
{
	int		i;
	t_token	*tmp;
	t_token	*next;

	tmp = NULL;
	next = NULL;
	i = 0;
	if (word)
	{
		free(*word);
		*word = NULL;
	}
	if (list && *list)
	{
		tmp = *list;
		while (tmp)
		{
			next = tmp->next;
			free(tmp->word);
			free(tmp);
			tmp = next;
		}
		*list = NULL;
	}
}
