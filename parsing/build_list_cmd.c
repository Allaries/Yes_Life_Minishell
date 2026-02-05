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

#include "../minishell.h"

int	build_list_cmd(t_cmd **cmd_list, t_token **tok_list)
{
	if (!fill_list_cmd(cmd_list, tok_list))
		return (0);
	return (1);
}

int	fill_list_cmd(t_cmd	**cmd_list, t_token **tok_list)
{
	int	i;

	i = 0;
	// while (tok_list[i])
	// {	init_args
	// 	find_args
	// 	create_args
	// 	init_redirs
	// 	find_redirs
	// 	build_list_redirs
	// 	init_cmd();
	// }
	return (1);
}
