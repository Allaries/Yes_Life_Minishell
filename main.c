/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:46 by smedenec          #+#    #+#             */
/*   Updated: 2025/12/20 04:53:23 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_list_word(t_token **list, char)
{

}

enum type_tok	which_type(char *word, enum type_tok type)
{
	int	i;

	i = 0;
	if (word[0] == '|' && !word[1])
		return (PIPE);
	return (CQUOI);
}

int	add_tok(t_token **list, char *word)
{
	enum type_tok	type;
	t_token			*tok;

	type = which_type(word, type);
	tok = new_tok(word, type);
	if (!tok)
	{
		free(word);
		word = NULL;
		return (1)
	}
}

char	*new_tok(char *word, enum type_tok type)
{
	t_token	*tok;

	tok = NULL;
	tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->word = word;
	tok->type = type;
	tok->next = NULL;
	return (tok);
}

int	is_space(char c)
{
	return ((c == ' ') || (c >= 8 && c <= 13));
}

int	browse_word(t_token **list, char *input, int *i)
{
	char	*word;
	int		start;
	int		len;
	int		y;

	y = 0;
	len = 0;
	start = *i;
	word = NULL;
	while (input[start + len] && !is_space(input[start + len]))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (1);
	while (y < len)
		word[y++] = input[(*i)++];
	word[y] = '\0';
	add_tok(list, word);
	free(word);
	word = NULL;
	if
	return (0);
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
			if (browse_word(&list, input, &i))
				return (1);
		else
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
