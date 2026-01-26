/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_list_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:32:15 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/26 14:08:47 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	verify_list_token(t_token **tok_list)
{
	if (!is_front_token(tok_list))
		return (0);
	if (!is_separated_token(tok_list))
		return (0);
	return (1);
}

int	is_front_token(t_token **tok_list)
{
	t_token			*tmp;

	tmp = *tok_list;
	if ((tmp->type) == 1 || (tmp->type) == 2 || (tmp->type) == 3
		|| (tmp->type) == 4 || (tmp->type) == 5)
		return (0);
	return (1);
}

int	is_separated_token(t_token **tok_list)
{
	t_token			*tmp;
	int				next_to;

	tmp = *tok_list;
	next_to = 0;
	while (tmp)
	{
		if ((tmp->type) == 1 || (tmp->type) == 2 || (tmp->type) == 3
			|| (tmp->type) == 4 || (tmp->type) == 5)
				next_to++;
		else
			next_to = 0;
		if (next_to > 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
