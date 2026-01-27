/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:43:16 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/27 15:17:05 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	iterate_input(t_token **tok_list, char *input)
{
	int	i;

	i = 0;
	if (!input || !input[0])
		return (1);
	while (input[i])
	{
		if (!is_space(input[i]))
		{
			if (!add_word_in_list(tok_list, input, &i))
				return (0);
		}
		else
			i++;
	}
	return (1);
}

int	add_word_in_list(t_token **tok_list, char *input)
{
	char	*word;
	int		i;

	i = 0;
	word = NULL;
	while (input[i])
	{
		if (is_space(input[i]))
			i++;
		else if (!create_word(input, word, &i))
			return (free_list_word(tok_list, &word), 0);
	}
	if (!add_tok_in_list(tok_list, &word))
		return (0);
	free_list_word(0, &word);
	return (1);
}

int	create_word(char *input, char *word, int *i)
{
	int	y;
	int	len;

	y = 0;
	len = 29;
	word = malloc(sizeof(char) * (len + 1));
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


