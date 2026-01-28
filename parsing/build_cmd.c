/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/28 14:02:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	build_cmd(char *input)
{
	t_token	*tok_list;

	tok_list = NULL;
	if (!build_list_token(&tok_list, input))
		return (0);
	// printf("Token :\n");
	// t_token	*tmp = tok_list;
	// while (tmp)
	// {
	// 	printf("str = %s type = %d\n", tmp->word, tmp->type_tok);
	// 	tmp = tmp->next;
	// }
	// ICI ajouter t_cmd cmd_list
	free_all(&tok_list, NULL);
	return (1);
}
