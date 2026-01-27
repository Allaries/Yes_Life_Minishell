/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:43:16 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/27 19:42:54 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	create_word(char *input, char *word, int *i)
{
	int	y;
	int	len;

	y = 0;
	len = 29;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (free_all(0, &word), 0);
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

int	is_word(char *input, int *i, char *q)
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


