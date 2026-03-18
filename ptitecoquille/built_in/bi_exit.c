/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:51:41 by rerichar          #+#    #+#             */
/*   Updated: 2026/03/18 20:58:36 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	bi_exit(t_data *data, t_cmd *cmd)
{
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		write(2, "exit\n", 5);
	if (cmd->args[1] != NULL)
		data->exit_code = ft_atoi(cmd->args[1]);
	if (cmd->poubelle != -1)
		close_all(data, cmd, cmd->poubelle);
	thanos_snap_process(data);
	if (data->exit_code == -1)
	{
		write (2, "exit : numeric argument required\n", 34);
		exit(2);
	}
	exit(data->exit_code);
}
