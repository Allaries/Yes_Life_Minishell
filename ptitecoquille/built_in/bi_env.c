/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:15:46 by rerichar          #+#    #+#             */
/*   Updated: 2026/03/15 22:02:42 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	bi_env(t_data *data, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		write(cmd->infd, data->envp[i], ft_strlen(data->envp[i]));
		write(cmd->infd, "\n", 1);
		i++;
	}
	return ;
}
