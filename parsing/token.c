/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/05 20:07:26 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	fill_list_token(char *input, t_token **tok_list)
{
	int		i;
	t_word	*word;

	i = 0;
	word = NULL;
	while (input[i])
	{
		if (is_space(input[i]))
			i++;
		else
		{
			word = init_word(32);
			if (!word)
				return (free_all(tok_list, NULL), 0);
			if (!parse_word(input, &word, &i))
				return (free_all(tok_list, &word), 0);
			if (!add_tok_in_list(tok_list, &word))
				return ((free_all(tok_list, &word), 0));
			free_all(NULL, &word);
		}
	}
	return (1);
}

int	add_tok_in_list(t_token **tok_list, t_word **word)
{
	enum e_tok	type;
	t_token		*tok;
	t_token		*tmp;

	type = which_type((*word)->buf);
	tok = create_token((*word)->buf, type);
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

t_token	*create_token(char *buf, enum e_tok type)
{
	t_token	*tok;

	tok = NULL;
	tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->word = ft_strduplicate(buf);
	if (!tok->word)
		return (free_token(tok), NULL);
	tok->type_tok = type;
	tok->next = NULL;
	return (tok);
}
