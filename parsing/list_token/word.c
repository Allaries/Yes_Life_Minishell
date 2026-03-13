/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:43:16 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/13 06:30:34 by marvin           ###   ########.fr       */
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
		return (free_word(&word), NULL);
	word->buf[0] = '\0';
	word->in_squote = 0;
	word->in_dquote = 0;
	word->was_quote = 0;
	word->was_token = 0;
	word->size = size;
	word->len = 0;
	return (word);
}

int	parse_word(char *input, t_data *data, t_word **word, int *i)
{
	char	c;

	c = 0;
	while (skip_quote(input, *word, i) && continue_word(input, *word, i))
	{
		c = input[*i];
		if (c == '$' && !(*word)->in_squote)
		{
			if (!expend_in_word(input, data, *word, i))
				return(0);
			continue;
		}
		if (!add_char_in_word(*word, c))
			return (0);
		(*i)++;
	}
	return (1);
}

int	skip_quote(char *input, t_word *word, int *i)
{
	int	q;

	q = which_quote_w(word);
	if (char_is_a_quote(input, *i))
	{
		if (word->was_token) // Pour le cas token dans le mot et une quote juste apres, s'arreter :  <<" "  >>''""u
			return (0);
		word->was_quote = 1;
		if (!q)
			toggle_quote_w(input, word, i);
		else if ((q == 1 && input[*i] == '\'') || (q == 2 && input[*i] == '"'))
			toggle_quote_w(input, word, i);
		else
			return (1);
		if (char_is_a_quote(input, *i))
			skip_quote(input, word, i); // Pour gerer les successions de mots vides : ""''""""a
	}
	if (!input[*i])
		return (0);
	return (1);
}

int	continue_word(char *input, t_word *word, int *i)
{
	char	c;
	int		q;

	q = which_quote_w(word);
	c = input[*i];
	if (!q)
	{
		if (is_space(c))
			return (0);
		if (word->was_quote && char_is_a_token(c)) // Pour s'arreter a un mot vide, juste avant un token : ""<
			return(0);
		if (is_tok(input, word, *i))
			return (0);
	}
	return (1);
}

int	is_tok(char *input, t_word *word, int i)
{
	char	c;
	char	c_prev;

	c = input[i];
	if (!word->len)
	{
		if (char_is_a_token(c)) // Pour signaler un vrai token dans word
			word->was_token = 1;
		return (0);
	}
	c_prev = input[i - 1];
	if (word->len == 1)
	{
		if ((c_prev == '>') && (c == '>'))
			return (0);
		if ((c_prev == '<') && (c == '<'))
			return (0);
	}
	if (char_is_a_token(c_prev))
		return (1);
	if (char_is_a_token(c))
		return (1);
	return (0);
}
