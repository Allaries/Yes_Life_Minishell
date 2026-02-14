/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:51:41 by rerichar          #+#    #+#             */
/*   Updated: 2026/02/14 04:25:23 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	bi_exit(t_data *data, t_cmd *cmd)
{
	printf("exit\n");
	close_all(data, cmd);
	thanos_snap_process(data);
	exit(0);
}