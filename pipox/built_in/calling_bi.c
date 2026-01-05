/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calling_bi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 01:36:53 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/05 16:52:49 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	bi_pwd(void)
{
	char	*pwd;
	
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		exit(1);
	}
	printf("%s\n", pwd);
	free (pwd);
}

void	bi_echo(char **cmd)
{
	//a ajuster apres que je sache comment les token ca marche
	if (strncmp(cmd[1], "-n", 3) == 0)
		printf("%s%%", cmd[2]);
	else
		printf("%s\n", cmd[1]);
}

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

void	bi_cd(char	**cmd)
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
		// else if (cmd[1] == NULL)
		// 	rajouter un truc qui va chercher le HOME= de l'env
		else
			path = slashcmd(cmd[1], pwd);
		chdir(path);
	}
	if (i == 0)
		printf("kus");
}



int	main(int ac, char **av, char** envp)
{
	char	**cpenv;

	cpenv = dupe_env(envp);
	int	i = 0;
	while (cpenv[i])
	{
		printf("%s\n", cpenv[i]);
		i++;
	}
	// char *cmd[4];

	// cmd[0] = "cat";
	// cmd[1] = "-n";
	// cmd[2] = "my fellas";
	// cmd[3] = NULL;
	
}