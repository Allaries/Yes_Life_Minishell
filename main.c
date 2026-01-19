/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:46 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/19 16:48:27 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptitecoquille/minishell.h"

int	ft_strcmp_safe(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (1);
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

enum e_type_tok	which_type(char *word)
{
	int	i;

	i = 0;
	if (!word)
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

t_token	*new_tok(char *word, enum e_type_tok type)
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

int	add_tok(t_token **tok_list, char **word)
{
	enum e_type_tok	type;
	t_token			*tok;
	t_token			*tmp;

	type = which_type(*word);
	tok = new_tok(*word, type);
	if (!tok)
		return (free_list_word(tok_list, word), 1);
	tmp = NULL;
	if (!*tok_list)
		*tok_list = tok;
	else
	{
		tmp = *tok_list;
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

int	is_tok(char *input, int start, int len)
{
	int	i;

	i = 0;
	if (!len)
		return (0);
	if ((len == 1) && (input[start + len - 1] == '>'))
		if (input[start + len] == '>')
			return (0);
	if ((len == 1) && (input[start + len - 1] == '<'))
		if (input[start + len] == '<')
			return (0);
	if ((input[start + len - 1] == '>') || (input[start + len - 1] == '<') || (input[start + len - 1] == '|'))
		return (1);
	if ((input[start + len] == '>') || (input[start + len] == '<') || (input[start + len] == '|'))
		return (1);
	return (0);
}

int	browse_word(t_token **tok_list, char *input, int *i)
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
	add_tok(tok_list, &word);
	free_list_word(0, &word);
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
			if (browse_word(tok_list, input, &i))
				return (1);
		}
		else
			i++;
	}
	return (0);
}

int	check_quote(char *input)
{
	return (1);
}

int	parsing(char *input)
{
	t_token	*tok_list;

	tok_list = NULL;
	if (check_quote(input))
		return (0);
	if (iterate_input(&tok_list, input))
		return (0);
	if (!tok_list)
		return (0);
	// printf("Token :\n");
	// t_token	*tmp = tok_list;
	// while (tmp)
	// {
	// 	printf("str = %s type = %d\n", tmp->word, tmp->type);
	// 	tmp = tmp->next;
	// }
	// ICI ajouter t_cmd cmd_list
	free_list_word(&tok_list, 0);
	return (1);
}

int	main(void)
{
	int		i;
	char	*input;

	i = 0;
	while (++i <= 1)
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
