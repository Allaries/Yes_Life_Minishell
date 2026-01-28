/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:43:16 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/28 15:00:44 by marvin           ###   ########.fr       */
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
	int	y;
	int	len;

	y = 0;
	len = 29;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (free_all(NULL, &word), 0);
	while (y < len)
	{
		if (*q && (input[*i] == *q))
				(*i)++;
		else
			word[y++] = input[(*i)++];
	}
	if (*q && (input[*i] == *q))
				(*i)++;
	word[y] = '\0';
	printf("i = %i\n", *i);
	printf("word = %s\n", (char *)word);
}

int	is_word(char *input, t_word **word, int *i)
{
	int		start;
	int		len;

	len = 0;
	start = *i;
	while (input[start + len] && !is_space(input[start + len])
		&& !is_tok(input, start, len) && ((!*q) || ((*q) && ((input[start + len] != '"') && (input[start + len] != '\'')))))
	{
		if (input[start + len] == '\'' || input[start + len] == '"')
		{
			if (!*q)
				*q = input[start + len];
			len++;
			while (input[start + len] && input[start + len] != *q)
				len++;
			len++;
			sleep(1);
		}
		else
			len++;
	}
	if (*q)
		len -= 2;
	if (!len)
		*i += 2;
	printf("len = %i\n", len);
	return (len);
}

// void word_add_char(t_word *w, char c, char mask)
// {
//     if (w->len + 1 >= w->size)
//         return; // ou realloc

//     w->buf[w->len] = c;
//     w->qmask[w->len] = mask;
//     w->len++;
//     w->buf[w->len] = '\0';
//     w->qmask[w->len] = '\0';
// }