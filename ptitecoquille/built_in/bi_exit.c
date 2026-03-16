/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:51:41 by rerichar          #+#    #+#             */
/*   Updated: 2026/03/16 23:20:04 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	bi_exit(t_data *data, t_cmd *cmd)
{
	write(2, "exit\n", 5);
	if (cmd->poubelle != -1)
		close_all(data, cmd, cmd->poubelle);
	thanos_snap_process(data);
	exit(data->exit_code);
}
