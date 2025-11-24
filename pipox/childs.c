/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 01:36:53 by rerichar          #+#    #+#             */
/*   Updated: 2025/11/24 21:31:28 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	close_all(t_data *data)
{
	if (close(data->pipefd[1]) == -1)
		return (0);
	if (close(data->pipefd[0]) == -1)
		return (0);
	if (close(data->outfd) == -1)
		return (0);
	if (close(data->infd) == -1)
		return (0);
	return (1);
}

exec_pipex(t_data *data, char **argv)
{
	int	i;

	i = 0;
	if (data->heredoc == 0)
	{
		while (i <= data->nb_of_cmd)
		{
			execute_child(argv, data, i);
			i++;
		}		
	}
}

int	execute_child(char **argv, t_data *data, int i)
{
	def_arg(argv[i + 2], data);
	def_path(data);
	pipe(data->pipefd);
	if (i == 0)
}

int	execute_child_one(char **argv, t_data *data)
{
	def_arg(argv[2], data);
	def_path(data);
	pipe(data->pipefd);
	data->pid1 = fork();
	if (data->pid1 == 0)
	{
		dup2(data->infd, 0);
		dup2(data->pipefd[1], 1);
		if (data->path == NULL)
		{
			close_all(data);
			free_struct(data);
			exit(127);
		}
		if (close_all(data) == 0)
			return (0);
		if (execve(data->path, data->args, data->envp) == -1)
			perror("Error ");
	}
	return (1);
}

int	execute_child_two(char **argv, t_data *data)
{
	def_arg(argv[3], data);
	def_path(data);
	data->pid2 = fork();
	if (data->pid2 == 0)
	{
		dup2(data->outfd, 1);
		dup2(data->pipefd[0], 0);
		if (data->path == NULL)
		{
			close_all(data);
			free_struct(data);
			exit(127);
		}
		if (close_all(data) == 0)
			return (0);
		if (execve(data->path, data->args, data->envp) == -1)
			perror("Error :");
	}
	return (1);
}
