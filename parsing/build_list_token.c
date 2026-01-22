/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/22 18:30:58 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	build_list_token(t_token **tok_list, char *input)
{
	if (iterate_input(tok_list, input))
		return (1);
	return (0);
}

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
			if (create_word(tok_list, input, &i))
				return (1);
		}
		else
			i++;
	}
	return (0);
}

int	create_word(t_token **tok_list, char *input, int *i)
{
	char	*word;
	int		start;
	int		len;
	int		y;

	y = 0;
	len = 0;
	start = *i;
	word = NULL;
	while ((input[start + len] && !is_space(input[start + len])
			&& !is_tok(input, start, len)))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (free_list_word(tok_list, &word), 1);
	while (y < len)
		word[y++] = input[(*i)++];
	word[y] = '\0';
	add_tok_in_list(tok_list, &word);
	free_list_word(0, &word);
	return (0);
}

