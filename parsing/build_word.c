/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:43:16 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/26 19:06:22 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	create_word(t_token **tok_list, char *input, int *i)
{
	char	*word;
	char	q;
	int		len;

	len = 0;
	q = '\0';
	word = NULL;
	len = is_word(input, i, &q);
	if (!len)
		return (1);
	if (q)
		word = malloc(sizeof(char) * (len + 1 - 2));
	else
		word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (free_list_word(tok_list, &word), 0);
	iterate_word(input, word, len, i, &q);
	if (!add_tok_in_list(tok_list, &word))
		return (0);
	free_list_word(0, &word);
	return (1);
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

void	iterate_word(char *input, char *word, int len, int *i, char *q)
{
	int	y;

	y = 0;
	printf("iterate\n");
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
