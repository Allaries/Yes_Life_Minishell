/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:19:56 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/05 15:10:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	first_one(char *input, t_word *word, int *i)
{
	if (which_quote(word) == '0' && ((input[*i] == '\'') || (input[*i] == '"')))
	{
		if (input[*i] == '\'')
			word->in_squote = 1;
		if (input[*i] == '"')
			word->in_dquote = 1;
		(*i)++;
		if (input[*i] == '\'')
			skip_one(input, word, i, '\'');
		if (input[*i] == '"')
			skip_one(input, word, i, '"');
	}
}

void	skip_one(char *input, t_word *word, int *i, char q)
{
	if (q == '\'')
	{
		if (input[*i] == '\'')
		{
			word->in_squote = 0;
			(*i)++;
		}
	}
	if (q == '"')
	{
		if (input[*i] == '"')
		{
			word->in_dquote = 0;
			(*i)++;
		}
	}
}

char	which_quote(t_word *word)
{
    if (word->in_dquote)
        return ('2');
    if (word->in_squote)
        return ('1');
    return ('0');
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

int	realloc_word(t_word *word)
{
	char	*tmp_buf;

	tmp_buf = NULL;
	word->size = word->size + word->size;
	tmp_buf = realloc(word->buf, word->size);
	if (!tmp_buf)
		return (0);
	word->buf = tmp_buf;
	return (1);
}
