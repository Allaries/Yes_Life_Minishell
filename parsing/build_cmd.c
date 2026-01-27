/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/27 18:40:44 by smedenec         ###   ########.fr       */
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
	free_all(&tok_list, 0);
	return (1);
}
