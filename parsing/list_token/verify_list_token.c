/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_list_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:32:15 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/13 00:42:46 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	verify_list_token(t_token **tok_list)
{
	t_token		*tmp;

	if (!tok_list || !*tok_list)
		return (0);
	tmp = *tok_list;
	if (!is_good_pipe(tmp))
		return (0);
	if (!is_good_token(tmp))
		return (0);
	if (!is_separated_token(tmp))
		return (0);
	return (1);
}

int	is_good_pipe(t_token *tok_list)
{
	if ((tok_list->type_tok) == PIPE)
		return (0);
	while (tok_list->next)
		tok_list = tok_list->next;
	if ((tok_list->type_tok) == PIPE)
		return (0);
	return (1);
}

int	is_good_token(t_token *tok_list)
{
	while (tok_list->next)
		tok_list = tok_list->next;
	if ((tok_list->type_tok) == REDIR_IN)
		return (0);
	if ((tok_list->type_tok) == REDIR_OUT)
		return (0);
	if ((tok_list->type_tok) == HEREDOC)
		return (0);
	if ((tok_list->type_tok) == APPEND)
		return (0);
	return (1);
}

int	is_separated_token(t_token *tok_list)
{
	int			next_to;

	next_to = 0;
	while (tok_list)
	{
		if ((tok_list->type_tok) == 2 || (tok_list->type_tok) == 3
			|| (tok_list->type_tok) == 4 || (tok_list->type_tok) == 5)
				next_to++;
		else
			next_to = 0;
		if (next_to > 1)
			return (0);
		tok_list = tok_list->next;
	}
	return (1);
}
