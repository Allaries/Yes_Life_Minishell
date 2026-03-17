/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:46:22 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/05 20:46:22 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	build_list_cmd(t_cmd **cmd_list, t_token **tok_list)
{
	if (!fill_list_cmd(cmd_list, tok_list))
	{
		printf("Memory error: cmd list allocation failed\n");
		return (0);
	}
	return (1);
}

int	fill_list_cmd(t_cmd	**cmd_list, t_token **tok_list)
{
	t_token	*tmp;

	tmp = *tok_list;
	while (tmp)
	{
		if (!add_cmd_in_list(cmd_list, tmp))
			return (free_list_cmd(cmd_list), free_list_token(tok_list), 0);
		while (tmp && tmp->type_tok != PIPE)
			tmp = tmp->next;
		if (tmp)
			tmp = tmp->next;
	}
	return (1);
}
