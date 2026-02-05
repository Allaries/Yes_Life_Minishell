/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:43:16 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/05 14:58:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_word	*init_word(int size)
{
	t_word	*word;

	word = NULL;
	word = malloc(sizeof(t_word));
	if (!word)
		return (NULL);
	word->buf = malloc(sizeof(char) * (size + 1));
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
	//return (0);// Pour tester si ca marche jusqu'a ici
	while (input[*i] && skip_quote(input, *word, i) && can_extend(input, *word, i))
	{
		char_buf = input[*i];
		if (!add_char_in_word(*word, char_buf))
				return (0);
		(*i)++;
	}
	return (1);
}

int	skip_quote(char *input, t_word *word, int *i)
{
	return (1); // Pour l'instant
	while (input[*i] && ((input[*i] == '\'') || (input[*i] == '"')))
	{
		first_one(input, word, i);
		if (word->in_squote)
		{
			skip_one(input, word, i, '\'');
			skip_one(input, word, i, '\'');
		}
		else if (word->in_dquote)
		{
			skip_one(input, word, i, '"');
			skip_one(input, word, i, '"');
		}	
	}
	if (!input[*i])
		return(0);
	return (1);
}

int	can_extend(char *input, t_word *word, int *i)
{
	char	c;
	char	q;

	q = which_quote(word);
	c = input[*i];
	if (q == '0' && ((c != '\'') && (c != '"')))
	{
		if (is_space(c))
			return (0);
		if (is_tok(input, *i, word->len))
			return (0);
	}
	else if (q == '1' || q == '2')
		return (1);
	return (1);
}


