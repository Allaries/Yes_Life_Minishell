/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/26 10:36:32 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	add_tok_in_list(t_token **tok_list, char **word)
{
	enum e_type_tok	type;
	t_token			*tok;
	t_token			*tmp;

	type = which_type(*word);
	tok = create_token(*word, type);
	if (!tok)
		return (free_list_word(tok_list, word), 0);
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

t_token	*create_token(char *word, enum e_type_tok type)
{
	t_token	*tok;

	tok = NULL;
	if (!word)
		return (NULL);
	tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->word = ft_strduplicate(word);
	if (!tok->word)
	{
		free(tok);
		return (NULL);
	}
	tok->type = type;
	tok->next = NULL;
	return (tok);
}
