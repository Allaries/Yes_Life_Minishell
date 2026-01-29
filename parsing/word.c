/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:43:16 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/29 18:38:36 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_word	*init_word(int size)
{
	t_word	*word;

	word = NULL;
	word = malloc(sizeof(sizeof(t_word)));
	if (!word)
		return (NULL);
	word->buf = malloc(sizeof(char) * (size + 1));
	if (!(word->buf))
		return (free_all(NULL, &word), NULL);
	word->qmask = malloc(sizeof(char) * (size + 1));
	if (!(word->qmask))
		return (free_all(NULL, &word), NULL);
	word->buf[0] = '\0';
	word->qmask[0] = '\0';
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
	{
		printf("size = %i\n", (*word)->size);
		return (0);// Pour tester si ca marche jusqu'a ici
	}
	while (input[*i] && is_word(input, *word, i))
	{
		char_buf = input[*i];
		if ((*word)->in_dquote)
			if (!add_char_in_word(*word, char_buf, '2'))
				return (0);
		if ((*word)->in_squote)
			if (!add_char_in_word(*word, char_buf, '1'))
				return (0);
		if (!((*word)->in_dquote) && !((*word)->in_dquote))
			if (!add_char_in_word(*word, char_buf, '0'))
				return (0);
		(*i)++;
	}
	return (1);
}

int	is_word(char *input, t_word *word, int *i)
{
	int	y;

	y = *i;
	if (!(word->in_squote) && !(word->in_dquote)
		&& input[*i] != '\'' && input[*i] != '"')
		return (0);
	if (is_space(input[y]))
		return (0);
	if (is_tok(input, y, word->len))
		return (0);
	return (1);
}
