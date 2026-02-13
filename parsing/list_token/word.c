/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:43:16 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/13 04:13:57 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_word	*init_word(int size)
{
	t_word	*word;

	word = NULL;
	word = ft_calloc(sizeof(t_word), 1);
	if (!word)
		return (NULL);
	word->buf = ft_calloc(sizeof(char) * (size + 1), 1);
	if (!(word->buf))
		return (free_all(NULL, &word), NULL);
	word->buf[0] = '\0';
	word->in_squote = 0;
	word->in_dquote = 0;
	word->expand = 0;
	word->size = size;
	word->len = 0;
	return (word);
}

int	parse_word(char *input, t_word **word, int *i)
{
	char	char_buf;

	char_buf = 0;
	while (input[*i] && skip_quote(input, *word, i) && can_extend(input, *word, i))
	{
		char_buf = input[*i];
		if (!add_char_in_word(*word, char_buf))
			return (0);
		(*i)++;
	}
	return (1);
}

int	add_char_in_word(t_word *word, char char_buf)
{
	if (word->len + 1 >= word->size)
		if (!realloc_word(word))
			return (0);
	word->buf[word->len] = char_buf;
	(word->len)++;
	word->buf[word->len] = '\0';
	return (1);
}

int	skip_quote(char *input, t_word *word, int *i)
{
	int	q;

	// return (1); // Pour l'instant
	q = which_quote(word);
	while (input[*i] && char_is_a_quote(input, *i))
	{
		if (!q)
			toggle_quote(input, word, i);
		else if (q == 1 && input[*i] == '\'')
			toggle_quote(input, word, i);
		else if (q == 2 && input[*i] == '"')
			toggle_quote(input, word, i);
		else
			return (1);
	}
	if (char_is_a_quote(input, *i)) // Pour gerer ""''""uf
		skip_quote(input, word, i);
	if (!input[*i])
		return (0);
	return (1);
}

int	can_extend(char *input, t_word *word, int *i)
{
	char	c;
	int		q;

	q = which_quote(word);
	c = input[*i];
	if (!q)
	{
		if (is_space(c))
			return (0);
		if (is_tok(input, *i, word->len))
			return (0);
	}
	else if (q)
		return (1); //Dans les quotes on laisse passer
	return (1);
}
