/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:46 by smedenec          #+#    #+#             */
/*   Updated: 2025/12/18 09:58:24 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*new_tok(char *name, enum type_tok type)
{
	t_token	*tok;

	tok = NULL;
	tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->name = name;
	tok->type = type;
	tok->next = NULL;
	return (tok);
}

int	is_space(char c)
{
	return ((c == ' ') || (c >= 8 && c <= 13));
}

void	browse_word(t_token **tok, char *input, int i)
{
	char	*word;
	int		len;
	int		y;

	y = 0;
	len = i;
	word = NULL;
	while (!is_space(input[len]))
		len++;
	word = malloc(sizeof(char) * len + 1);
	while (len--)
		word[y++] = input[i++];
	word[y] = '\0';
}

void	iterate_input(char *input)
{
	t_token	*list;
	int		i;

	i = 0;
	list = NULL;
	if (!input[0])
		return ;
	while (input[i])
	{
		if (!is_space(input[i]))
			put_word(&list, input, i);
		i++;
	}
}

void	parsing(char *input)
{
	iterate_input(input);
}

int	main(void)
{
	int		i;
	char	*input;

	i = 0;
	while (i++ <= 4)
	{
		input = readline(NULL);
		if (!input)
		{
			perror("Error");
			return (1);
		}
		parsing(input);
		free(input);
		input = NULL;
	}
	return (0);
}
