/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/28 16:23:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	add_tok_in_list(t_token **tok_list, char **word)
{
	enum e_tok	type;
	t_token		*tok;
	t_token		*tmp;

	type = which_type((*word)->buf);
	tok = create_token((*word)->buf, (*word)->qmask, type);
	if (!tok)
		return (0);
	tmp = NULL;
	if (!*tok_list)
		*tok_list = tok;
	else
	{
		tmp = *tok_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = tok;
	}
	return (1);
}

t_token	*create_token(char *buf, char *qmask enum e_tok type)
{
	t_token	*tok;

	tok = NULL;
	tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->word = ft_strduplicate(buf);
	tok->qmask = ft_strduplicate(qmask);
	if (!tok->word || !tok->qmask)
	{
		free(tok->word);
		free(tok->qmask);
		free(tok);
		return (NULL);
	}
	tok->type_tok = type;
	tok->next = NULL;
	return (tok);
}
