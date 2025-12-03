/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 01:36:53 by rerichar          #+#    #+#             */
/*   Updated: 2025/12/03 20:42:14 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	close_all(t_data *data)
{
	if (close(data->pipefd[1][0]) == -1)
		return (0);
	if (close(data->pipefd[1][1]) == -1)
		return (0);
	if (close(data->pipefd[0][0]) == -1)
		return (0);
	if (close(data->pipefd[0][1]) == -1)
		return (0);
	if (close(data->outfd) == -1)
		return (0);
	if (close(data->infd) == -1)
		return (0);
	printf("fini\n");
	return (1);
}

void	close_daddy_prime(t_data *data, int i)
{
	if (i == 0)
	{
		close (data->infd);
		close (data->pipefd[i % 2][1]);
	}
	else if (i == data->nb_of_cmd)
		close_all(data);
	else
	{
		close(data->pipefd[(i + 1) % 2][0]);
		close(data->pipefd[i % 2][1]);
	}
}

void	dup2_child_hack(t_data *data, int i)
{
	fprintf (stderr, " i = %d, nb cmd = %d\n", i, data->nb_of_cmd);
	if (i == 0)
	{
		dup2(data->infd, 0);
		dup2(data->pipefd[i % 2][1], 1);
	}
	else if (i == data->nb_of_cmd - 1)
	{
		dup2(data->pipefd[(i + 1) % 2][0], 0);
		dup2(data->outfd, 1);
		fprintf (stderr, "cic\n");
	}
	else
	{
		fprintf (stderr, "MIDDLE\n");
		dup2(data->pipefd[(i + 1) % 2][0], 0);
		dup2(data->pipefd[i % 2][1], 1);
	}
	// fprintf(stderr, "%i, %i\n%i, %i\n", data->pipefd[0][0], data->pipefd[0][1], data->pipefd[1][0], data->pipefd[1][1]);
	// fprintf(stderr ,"------------------------------\n%i, %i\n", data->pipefd[(i + 1) % 2][0], data->pipefd[(i + 1) % 2][1]);
	// fprintf(stderr ,"%i, %i\n ------------------------------\n", data->pipefd[i % 2][0], data->pipefd[i % 2][1]);
}

int	execute_child(char **argv, t_data *data, int i)
{
	def_arg(argv[i + 2], data);
	def_path(data);
	data->pid[i] = fork();
	if (data->pid[i] != 0)
	{
		return (1);
	}
	fprintf(stderr, "%s\n", data->path);
	if (data->path == NULL)
	{
		close_all(data);
		free_struct(data);
		exit(127);
	}
	// fprintf(stderr ,"before the dup2 hack 300cs/min\n");
	dup2_child_hack(data, i);
	// if (close_all(data) == 0)
	// 	exit(127);
	// fprintf(stderr ,"je execve hihi\n");
	if (execve(data->path, data->args, data->envp) == -1)
		perror("Error ");
	exit(127);
}

int	exec_pipex (char **argv, t_data *data)
{
	int	i;
	int		status;

	i = 0;
	if (data->heredoc == 0)
	{
		while (i < data->nb_of_cmd)
		{
			if (i < data->nb_of_cmd)
				pipe(data->pipefd[i % 2]);
			execute_child(argv, data, i);
			if (data->pid[i] != 0)
				close_all(data);
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
// 	pipe(data->pipefd);
// 	data->pid1 = fork();
// 	if (data->pid1 == 0)
// 	{
// 		dup2(data->infd, 0);
// 		dup2(data->pipefd[1], 1);
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
// 		dup2(data->pipefd[0], 0);
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
