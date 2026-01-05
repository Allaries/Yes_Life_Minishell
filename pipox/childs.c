/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 01:36:53 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/05 13:17:32 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	close_all(t_data *data)
{
	close(data->oldpipe[0]);
	close(data->oldpipe[1]);
	close(data->newpipe[0]);
	close(data->newpipe[1]);
	close(data->outfd);
	close(data->infd);
	return (1);
}


void	close_daddy_prime(t_data *data, int i)
{
	if (i == 0)
	{
		close (data->infd);
		close (data->newpipe[1]);
	}
	else if (i == data->nb_of_cmd - 1)
		close_all(data);
	else
	{
		close(data->oldpipe[0]);
		close(data->newpipe[1]);
	}
}

void	dup2_child_hack(t_data *data, int i)
{
	if (i == 0)
	{
		dup2(data->infd, 0);
		dup2(data->newpipe[1], 1);
	}
	else if (i == data->nb_of_cmd - 1)
	{
		dup2(data->oldpipe[0], 0);
		dup2(data->outfd, 1);
	}
	else
	{
		dup2(data->oldpipe[0], 0);
		dup2(data->newpipe[1], 1);
	}
}

int	execute_child(char **argv, t_data *data, int i)
{
	data->pid[i] = fork();
	if (data->pid[i] != 0)
	{
		return (1);
	}
	def_arg(argv[i + 2], data);
	def_path(data);
	if (data->path == NULL)
	{
		close_all(data);
		free_struct(data);
		exit(127);
	}
	dup2_child_hack(data, i);
	if (i != 0 && close_all(data) == 0)
	{
		fprintf(stderr, "close error at i = %i\n", i);
		exit(127);
	}
	if (execve(data->path, data->args, data->envp) == -1)
		perror("Error ");
	exit(127);
}

void	adv_pipe(t_data *data)
{
	data->oldpipe[0] = data->newpipe[0];
	data->oldpipe[1] = data->newpipe[1];
}

int	exec_pipex(char **argv, t_data *data)
{
	int	i;
	int	status;

	i = 0;
	if (data->heredoc == 0)
	{
		while (i < data->nb_of_cmd)
		{
			if (i < data->nb_of_cmd - 1)
				pipe(data->newpipe);
			execute_child(argv, data, i);
			close_daddy_prime(data, i);
			adv_pipe(data);
			i++;
		}
		if (data->pid[i] != 0)
		{
			i = 0;
			while (data->pid[i])
			{
				waitpid(data->pid[i], &status, 0);
				i++;
			}
		}
	}
	return (1);
}


// int	execute_p_fd[2];child_one(char **argv, t_data *data)
// {
// 	def_arg(argv[2], data);
// 	def_path(data);
// 	pipe(data->pipe);
	// data->pid1 = fork();
// 	if (data->pid1 == 0)
// 	{
// 		dup2(data->infd, 0);
// 		dup2(data->pipe[1]);
// 		if (data->path == NULL)
// 		{
// 			close_all(data);
// 			free_struct(data);
// 			exit(127);
// 		}
// 		if (close_all(data) == 0)
// 			return (0);
// 		if (execve(data->path, data->args, data->envp) == -1)
// 			perror("Error ");
// 	}
// 	return (1);
// }

// int	execute_child_two(char **argv, t_data *data)
// {
// 	def_arg(argv[3], data);
// 	def_path(data);
// 	data->pid2 = fork();
// 	if (data->pid2 == 0)
// 	{
// 		dup2(data->outfd, 1);
// 		dup2(data->pipe[0]);
// 		if (data->path == NULL)
// 		{
// 			close_all(data);
// 			free_struct(data);
// 			exit(127);
// 		}
// 		if (close_all(data) == 0)
// 			return (0);
// 		if (execve(data->path, data->args, data->envp) == -1)
// 			perror("Error :");
// 	}
// 	return (1);
// }
