/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 01:36:39 by rerichar          #+#    #+#             */
/*   Updated: 2025/12/21 05:51:25 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*slashcmd(char *cmd, char *path)
{
	char	*temp;

	temp = ft_strjoin("/", cmd);
	if (!temp)
		return (NULL);
	// free(cmd);
	cmd = ft_strjoin(path, temp);
	if (!cmd)
		return (NULL);
	free (temp);
	return (cmd);
}

int	abs_path_check(char *cmd, t_data *data)
{
	if (cmd[0] == '/')
	{
		if (access (data->cmd, F_OK) == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}

int	find_path(t_data *data, char **path)
{
	char	*cmd;
	int		i;

	i = 0;
	if (abs_path_check(data->cmd, data) == 1)
		{
			data->path = ft_strdup(data->cmd);
			return (free_tab(path), 1);
		}
	while (path[i])
	{
		cmd = ft_strdup(data->cmd);
		if (!cmd)
			return (free_tab(path), 0);
		data->path = slashcmd(cmd, path[i]);
		if (!data->path)
			return (free_tab(path), 0);
		if (access (data->path, F_OK) == 0)
			return (free_tab(path), 1);
		else
			free(data->path);
		i++;
	}
	data->path = NULL;
	free_tab(path);
	return (0);
}

int	def_path(t_data *data)
{
	char	**path;
	int		i;
	char	*temp;

	i = 0;
	while (ft_strncmp(data->envp[i], "PATH=", 5) != 0)
		i++;
	path = ft_split(data->envp[i], ':');
	if (!path || !path[0])
		return (0);
	i = 0;
	temp = ft_strdup(ft_strnstr(path[0], "/", 6));
	free(path[0]);
	path[0] = ft_strdup(temp);
	free(temp);
	find_path(data, path);
	return (1);
}

int	check_argv(int argc, char **argv, char **envp)
{
	int	i;

	i = 0;
	while (argv[i] && argv[i][0] != '\0')
		i++;
	if (argc < 5 && ft_strncmp(argv[1], "here_doc", 8) != 0)
		return (printf ("not here"), 0);
	if (argc < 6 && ft_strncmp(argv[1], "here_doc", 8) == 0)
		return (printf ("yes here"), 0);
	if (!envp || !envp[0])
		return (0);
	return (1);
}

void	check_nb_cmd(t_data *data, char **argv, int argc)
{
	int	i;

	i = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) != 0)
	{
		while (argv[i])
			i++;
		data->nb_of_cmd = argc - 3;
	}
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		while (argv[i])
			i++;
		data->nb_of_cmd = i - 4;
		data->heredoc = 1;
	}
	data->pid = ft_calloc(sizeof (int *) * data->nb_of_cmd, 1);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	t_data	*data;

// 	if (check_argv(argc, argv, envp) == 0)
// 		return (error(1), 0);
// 	data = ft_calloc(sizeof(t_data), 1);
// 	check_nb_cmd(data, argv, argc);
// 	if (!data)
// 		return (0);
// 	data->envp = envp;
// 	if (check_fd(argv, data) == 0)
// 		return (free_struct(data), 0);
// 	exec_pipex(argv, data);
// 	free_struct(data);
// }
