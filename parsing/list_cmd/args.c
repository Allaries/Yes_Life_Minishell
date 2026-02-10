/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:54:58 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/10 15:17:03 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**fill_args(t_token *tok_list)
{
	int		len;
	t_token	*tmp;
	char	**args;

	len = 0;
	tmp = tok_list;
	while (tmp && tmp->type_tok != PIPE)
	{
		if (tmp->type_tok == ARG)
			len++;
		tmp = tmp->next;
	}
	if (!len) // au cas ou
		return (NULL);
	args = ft_calloc(sizeof(char *) * (len + 1), 1);
	if (!args)
		return (NULL);
	len = 0;
	while (tok_list && tok_list->type_tok != PIPE)
	{
		if (tok_list->type_tok == ARG)
		{
			args[len] = ft_strduplicate(tok_list->word);
			if (!args[len])
				return (NULL);
			len++;
		}
		tok_list = tok_list->next;
	}
	return (args);
}
