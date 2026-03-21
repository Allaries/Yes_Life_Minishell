/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:51:39 by rerichar          #+#    #+#             */
/*   Updated: 2026/03/20 19:58:38 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*gethome(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if (strncmp(envp[i], "HOME=", 5) == 0)
			return (ft_strchr(envp[i], '/'));
	}
	return (NULL);
}

void	change_pwd(t_data *data)
{
	char	*pwd;
	char	*get;
	int		nofree;

	nofree = 0;
	pwd = getcwd(NULL, 0);
	if (!pwd || pwd == NULL)
	{
		pwd = "void";
		nofree = 1;
	}
	get = ft_strjoin("OLDPWD=", get_env(data, "PWD"));
	export_one(data, get);
	free (get);
	get = ft_strjoin("PWD=", pwd);
	export_one(data, get);
	free (get);
	if (!nofree)
		free (pwd);
}

int	bi_cd(char **cmd, char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (cmd[i])
		i++;
	if (i > 2)
		return (write(2, "cd : too many argument\n", 24), 1);
	if (i == 1)
	{
		path = gethome(envp);
		if (!path || path == NULL)
			return (print_stderr("cd : HOME not set", 2), 1);
		if (chdir(path) != 0)
			return (1);
		return (0);
	}
	if (strncmp(cmd[1], ".", 2) == 0)
		return (0);
	if (chdir(cmd[1]) != 0)
		return (print_stderr(cmd[1], 2), 1);
	return (0);
}
