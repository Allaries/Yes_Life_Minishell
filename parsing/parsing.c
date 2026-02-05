/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/05 17:10:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parsing(char *input)
{
	t_token	*tok_list;
	t_cmd	*cmd_list;

	tok_list = NULL;
	cmd_list = NULL;
	if (!build_list_token(input, &tok_list))
		return (0);
	if (!build_list_cmd(&cmd_list, &tok_list))
		return (0);
	// printf("Token :\n");
	// t_token	*tmp = tok_list;
	// while (tmp)
	// {
	// 	printf("str = %s type = %d\n", tmp->word, tmp->type_tok);
	// 	tmp = tmp->next;
	// }
	//ICI ajouter t_cmd cmd_list
	free_all(&tok_list, NULL);
	//appell d'exec
	return (1);
}
