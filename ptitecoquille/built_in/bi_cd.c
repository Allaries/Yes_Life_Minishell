/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:51:39 by rerichar          #+#    #+#             */
/*   Updated: 2026/02/23 17:13:29 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*cut_path(char *unc_path)
{
	int		i;
	char	*path;

	i = 0;
	while (unc_path[i])
		i++;
	while (unc_path[i] != '/')
		i--;
	path = ft_substr(unc_path, 0, i);
	return (path);
}

char	*gethome(char **envp)
{
	int	i;
	
	i = -1;
	while(envp[++i])
	{
		if(strncmp(envp[i], "HOME=", 5) == 0)
			return (ft_strchr(envp[i], '/'));
	}
	return (NULL);
}

int	chdir_nopwd(char **cmd, int mod, char **envp)
{
	char *path;

	if (mod == 0)
	{
		path = gethome(envp);
		if (!path || path == NULL)
			return (printf("cd : HOME not set\n"), 1);
		if (chdir(path) != 0)
			return (1);
		return (0);
	}
	if (mod == 1)
	{
		path = cmd[1];
		if (chdir(path) != 0)
			return (1);
		return (0);
	}
	return (0);
}

int	chdir_pwd(char **cmd, int mod)
{
	char	*pwd;
	char	*path;
	
	pwd = getcwd(NULL, 0);
	// if (!pwd || pwd == NULL)
	// {
	// 	printf("you are stuck in this reality\n");
	// 	return (1);
	// }
	if (mod == 0)
		path = slashcmd(cmd[1], pwd);
	if (mod == 1)
	{
		chdir("..bvvhgvghcgfc");
		return (0);
	}
	if (chdir(path) != 0)
	{
		free(pwd);
		free(path);
		return (1);
	}
	free(pwd);
	free(path);
	return (0);
}


int	bi_cd(char **cmd, char **envp)
{
	int		i;
	char	*pwd;
	char	*path;
	
	i = 0;
	while (cmd[i])
		i++;
	if (i > 2)
		return (printf("cd : too many argument\n"), 1);
	if (i == 1)
		return (chdir_nopwd(cmd, 0, envp));
	if (strncmp(cmd[1], ".", 2) == 0)
		return (0);
	if (cmd[1][0] == '/')
		return (chdir_nopwd(cmd, 1, envp));
	else if (strncmp(cmd[1], "..", 3) == 0)
		return (chdir_pwd(cmd, 1));
	else
		return (chdir_pwd(cmd, 0));
	return (0);
}
