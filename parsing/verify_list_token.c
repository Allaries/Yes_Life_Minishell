/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_list_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:32:15 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/08 19:48:14 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	verify_list_token(t_token **tok_list)
{
	if (!is_good_pipe(tok_list))
		return (0);
	// if (!is_separated_token(tok_list))
	// 	return (0);
	return (1);
}
// is_back_token

int	is_good_pipe(t_token **tok_list)
{
	t_token		*tmp;

	tmp = *tok_list;
	if ((tmp->type_tok) == 1)
		return (0);
	while (tmp->next)
		tmp = tmp->next;
	if ((tmp->type_tok) == 1)
		return (0);
	return (1);
}

int	is_separated_token(t_token **tok_list)
{
	t_token		*tmp;
	int			next_to;

	tmp = *tok_list;
	next_to = 0;
	while (tmp)
	{
		if ((tmp->type_tok) == 1 || (tmp->type_tok) == 2 || (tmp->type_tok) == 3
			|| (tmp->type_tok) == 4 || (tmp->type_tok) == 5)
				next_to++;
		else
			next_to = 0;
		if (next_to > 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
