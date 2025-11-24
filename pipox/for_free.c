/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 22:36:20 by rerichar          #+#    #+#             */
/*   Updated: 2025/09/25 23:07:25 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}

void	free_struct(t_data *data)
{
	if (data->args)
		free_tab(data->args);
	if (data->path)
		free(data->path);
	if (data)
		free(data);
}

void	def_arg(char *cmd, t_data *data)
{
	data->args = ft_split(cmd, ' ');
	if (data->args)
		data->cmd = data->args[0];
}

int	check_fd(char **argv, t_data *data)
{
	data->infd = open(argv[1], O_RDONLY);
	if (data->infd == -1)
	{
		write(2, "problem during infile open\n", 27);
		return (0);
	}
	data->outfd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (data->outfd == -1)
	{
		close (data->infd);
		write(2, "problem during outfile open\n", 28);
		return (0);
	}
	return (1);
}

void	error(int type)
{
	if (type == 1)
		write (2, "invalid arguments\n", 18);
}
