/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_struct_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/22 18:56:27 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	build_cmd(char *input)
{
	t_token	*tok_list;

	tok_list = NULL;
	if (check_quote(input))
		return (0);
	if (iterate_input(&tok_list, input))
		return (0);
	if (!tok_list)
		return (0);
	printf("Token :\n");
	t_token	*tmp = tok_list;
	while (tmp)
	{
		printf("str = %s type = %d\n", tmp->word, tmp->type);
		tmp = tmp->next;
	}
	//ICI ajouter t_cmd cmd_list
	free_list_word(&tok_list, 0);
	return (1);
}
