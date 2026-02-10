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

int	parsing(char *input, t_data *data)
{
	t_token	*tok_list;
	t_cmd	*cmd_list;

	tok_list = NULL;
	cmd_list = NULL;
	if (!expend_input(input)) // expend_input -> malloc new input
		return (0);
	if (!build_list_token(input, &tok_list))
		return (0);
	if (!build_list_cmd(&cmd_list, &tok_list))
		return (0);
	free_list_token(&tok_list);
	data->cmd = &cmd_list;
	exec_pipex(data, data->cmd);
	return (1);
}
