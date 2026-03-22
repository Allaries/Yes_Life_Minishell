/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 01:36:39 by rerichar          #+#    #+#             */
/*   Updated: 2026/03/17 23:29:06 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*slashcmd(char *cmd, char *path)
{
	char	*temp;

	temp = ft_strjoin("/", cmd);
	if (!temp)
		return (NULL);
	cmd = ft_strjoin(path, temp);
	if (!cmd)
		return (NULL);
	free (temp);
	return (cmd);
}

int	abs_path_check(char *cmd)
{
	if (cmd[0] == '/')
	{
		if (access (cmd, F_OK) == 0)
			return (1);
		else
			return (0);
	}
	else if (cmd[0] == '.' && cmd[1] == '/')
	{
		if (access (cmd, F_OK) == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}

int	find_path(t_cmd *cmd, char **path)
{
	char	*cm2d;
	int		i;

	i = 0;
	while (path[i])
	{
		cm2d = ft_strdup(cmd->args[0]);
		if (!cmd)
			return (free_tab(path), 0);
		cmd->path = slashcmd(cm2d, path[i]);
		free (cm2d);
		if (!cmd->path)
			return (free_tab(path), 0);
		if (access (cmd->path, F_OK) == 0)
			return (free_tab(path), 1);
		else
			free(cmd->path);
		i++;
	}
	cmd->path = NULL;
	free_tab(path);
	return (0);
}

int	def_path(t_data *data, t_cmd *cmd)
{
	char	**path;
	int		i;
	char	*temp;

	i = 0;
	if (!cmd->args)
		return (cmd->poubelle = 1, 0);
	if (abs_path_check(cmd->args[0]) == 1)
		return (cmd->path = ft_strdup(cmd->args[0]), 1);
	if (!data->envp)
		return (1);
	while (data->envp[i] && ft_strncmp(data->envp[i], "PATH=", 5) != 0)
		i++;
	if (!data->envp[i])
		return (cmd->path = NULL, 0);
	path = ft_split(data->envp[i], ':');
	if (!path || !path[0])
		return (cmd->path = NULL, 0);
	i = 0;
	temp = ft_strdup(ft_strnstr(path[0], "/", 6));
	free(path[0]);
	path[0] = ft_strdup(temp);
	free(temp);
	return (find_path(cmd, path));
}
