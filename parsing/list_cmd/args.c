/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:54:58 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/17 23:33:26 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	fill_args(char ***args, t_token *tok_list)
{
	int	len;
	int	i;

	i = 0;
	len = argslen(tok_list);
	if (!len)
		return (1);
	*args = ft_calloc(sizeof(char *) * (len + 1), 1);
	if (!*args)
		return (0);
	while (tok_list && tok_list->type_tok != PIPE)
	{
		if (tok_list->type_tok == ARG)
		{
			(*args)[i] = ft_strduplicate(tok_list->word);
			if (!(*args)[i])
				return (0);
			i++;
		}
		tok_list = tok_list->next;
	}
	(*args)[i] = NULL;
	return (1);
}

int	argslen(t_token *tok_list)
{
	t_token	*tmp;
	int		len;

	len = 0;
	tmp = tok_list;
	while (tmp && tmp->type_tok != PIPE)
	{
		if (tmp->type_tok == ARG)
			len++;
		tmp = tmp->next;
	}
	return (len);
}
