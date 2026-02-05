/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/05 19:08:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	build_list_token(char *input, t_token **tok_list)
{
	if (!check_input(input))// expend_input -> modify input
		return (0);
	if (!check_quote(input))
		return (0);
	if (!fill_list_token(input, tok_list))
		return (0);
	if (!verify_list_token(tok_list))
		return (0);
	if (!modify_list_token(tok_list))
		return (0);
	return (1);
}

int	fill_list_token(char *input, t_token **tok_list)
{
	int		i;
	t_word	*word;

	i = 0;
	word = NULL;
	while (input[i])
	{
		if (is_space(input[i]))
			i++;
		else
		{
			word = init_word(32);
			if (!word)
				return (free_all(tok_list, NULL), 0);
			if (!parse_word(input, &word, &i))
				return (free_all(tok_list, &word), 0);
			if (!add_tok_in_list(tok_list, &word))
				return ((free_all(tok_list, &word), 0));
			free_all(NULL, &word);
		}
	}
	return (1);
}

int	modify_list_token(t_token **tok_list)
{
	int		i;
	t_token	*tmp;
	
	i = 0;
	tmp = NULL;
	tmp = *tok_list;
	while (tmp)
	{
		if (tmp->type_tok == REDIR_IN || tmp->type_tok == REDIR_OUT
			|| tmp->type_tok == HEREDOC || tmp->type_tok == APPEND)
		{
			modify_type_tok
		}
		else
			tmp = tmp->next;
	}
}