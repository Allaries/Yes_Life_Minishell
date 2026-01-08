/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:51:39 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/07 18:49:51 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void	chdir_and_env(char *path, char **envp)
{
	int	i;
	int	j;

	if(chdir(path) == -1)
	{
		perror(" cd : Error ");
		return ;
	}
	i = 0;
	envp export_one()
}

char	*gethome(char **envp)
{
	int	i;
	
	i = 0;
	while(envp[i])
	{
		if(strncmp(envp[i], "HOME=", 5) == 0)
			return (ft_strchr(envp[i], '/'));
	}
	return (NULL);
}

void	bi_cd(char **cmd, char **envp)
{
	int		i;
	char	*pwd;
	char	*path;
	
	i = 0;
	while (cmd[i])
		i++;
	if (i >= 2)
	{
		printf("cd : too many argument\n");
		printf("%i\n", i);
		return ;
	}
	pwd = getcwd(NULL, 0);
	if (i == 2)
	{
		if (cmd[1][0] == '/')
			path = cmd[1];
		if (strncmp(cmd[1], ".", 2) == 0)
			return ;
		else if (strncmp(cmd[1], "..", 3) == 0)
			path = cut_path(pwd);
		if (cmd[1] == NULL)
		{
			path = get_home(envp);
			if (!path)
				return (printf("minishell : cd : HOME not set"));
		}
		else
			path = slashcmd(cmd[1], pwd);
		free(path);
	}
	if (i == 0)
		printf("kus");
}