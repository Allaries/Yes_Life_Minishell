/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:54:58 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/14 02:10:33 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**fill_args(t_token *tok_list)
{
	int		len;
	char	**args;

	len = argslen(tok_list);
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
