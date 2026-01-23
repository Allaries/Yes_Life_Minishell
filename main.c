/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:46 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/23 18:38:53 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptitecoquille/minishell.h"

int	ft_strcmp_safe(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return 1;
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}


void	free_list_word(t_token **list, char **word)
{
	int		i;
	t_token	*tmp;
	t_token	*next;

	tmp = NULL;
	next = NULL;
	i = 0;
	if (word)
	{
		free(*word);
		*word = NULL;
	}
	if (list && *list)
	{
		tmp = *list;
		while (tmp)
		{
			next = tmp->next;
			free(tmp->word);
			free(tmp);
			tmp = next;
		}
		*list = NULL;
	}
}

enum type_tok	which_type(char *word)
{
	int	i;

	i = 0;
	if(!word)
		return (CQUOI);
	if (!ft_strcmp_safe(word, "<"))
		return (REDIR_IN);
	if (!ft_strcmp_safe(word, ">"))
		return (REDIR_OUT);
	if (!ft_strcmp_safe(word, "<<"))
		return (HEREDOC);
	if (!ft_strcmp_safe(word, ">>"))
		return (APPEND);
	if (!ft_strcmp_safe(word, "|"))
		return (PIPE);
	return (ARG);
}

t_token	*new_tok(char *word, enum type_tok type)
{
	t_token	*tok;

	tok = NULL;
	if (!word)
		return (NULL);
	tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->word = ft_strdup(word);
	if (!tok->word)
	{
		free(tok);
		return (NULL);
	}
	tok->type = type;
	tok->next = NULL;
	return (tok);
}

int	add_tok(t_token **list, char **word)
{
	enum type_tok	type;
	t_token			*tok;
	t_token			*tmp;

	type = which_type(*word);
	tok = new_tok(*word, type);
	if (!tok)
		return (free_list_word(list, word), 1);
	tmp = NULL;
	if (!*list)
		*list = tok;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = tok;
	}
	return (0);
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
		return (free_list_word(list, &word), 1);
	while (y < len)
		word[y++] = input[(*i)++];
	word[y] = '\0';
	add_tok(list, &word);
	free_list_word(0, &word);
	return (0);
}

int	iterate_input(t_token **list, char *input)
{
	int	i;

	i = 0;
	if (!input || !input[0])
		return (1);
	while (input[i])
	{
		if (!is_space(input[i]))
		{
			if (browse_word(list, input, &i))
				return (1);
		}
		else
			i++;
	}
	return (0);
}

int	parsing(char *input)
{
	t_token	*list;

	list = NULL;
	if(iterate_input(&list, input))
		return (1);
	if (!list)
		return (1);
	printf("Token :\n");
	t_token	*tmp = list;
	while (tmp)
	{
		printf("str = %s type = %d\n", tmp->word, tmp->type);
		tmp = tmp->next;
	}
	free_list_word(&list, 0);
	return (0);
}

// int	main(void)
// {
// 	int		i;
// 	char	*input;

// 	i = 0;
// 	while (i++ <= 4)
// 	{
// 		input = readline(NULL);
// 		if (!input)
// 		{
// 			perror("Error");
// 			return (1);
// 		}
// 		parsing(input);
// 		free(input);
// 		input = NULL;
// 	}
// 	return (0);
// }
