/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 01:36:53 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/02 19:16:18 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	bi_pwd(void)
// {
// 	char	*pwd;
	
// 	pwd = getcwd(NULL, 0);
// 	if (pwd == NULL)
// 	{
// 		exit(1);
// 	}
// 	printf("%s\n", pwd);
// 	free (pwd);
// }

// void	bi_echo(char **cmd)
// {
// 	//a ajuster apres que je sache comment les token ca marche
// 	if (strncmp(cmd[1], "-n", 3) == 0)
// 		printf("%s", cmd[2]);
// 	else
// 		printf("%s\n", cmd[1]);
// }

// char	*cut_path(char *unc_path)
// {
// 	int		i;
// 	char	*path;

// 	i = 0;
// 	while (unc_path[i])
// 		i++;
// 	while (unc_path[i] != '/')
// 		i--;
// 	path = ft_substr(unc_path, 0, i);
// 	return (path);
// }

// void	bi_cd(char	**cmd)
// {
// 	int		i;
// 	char	*pwd;
// 	char	*path;
	
// 	i = 0;
// 	while (cmd[i])
// 		i++;
// 	if (i >= 2)
// 	{
// 		printf("cd : too many argument\n");
// 		printf("%i\n", i);
// 		return ;
// 	}
// 	pwd = getcwd(NULL, 0);
// 	if (i == 2)
// 	{
// 		if (cmd[1][0] == '/')
// 			path = cmd[1];
// 		if (strncmp(cmd[1], ".", 2) == 0)
// 			return ;
// 		else if (strncmp(cmd[1], "..", 3) == 0)
// 			path = cut_path(pwd);
// 		// else if (cmd[1] == NULL)
// 		// 	rajouter un truc qui va chercher le HOME= de l'env
// 		else
// 			path = slashcmd(cmd[1], pwd);
// 		chdir(path);
// 	}
// 	if (i == 0)
// 		printf("kus");
// }

// void	bi_export(char **envp, char *export)
// {
// 	char	**new_env;
// 	int		i;
// 	int		check;
	
// 	i = 0;
// 	env_already_exist(envp, export);
// 	while (envp[i])
// 	{
// 		env_already_exist(envp, export);
// 		i++;
// 	}
// 	new_env = calloc(i, 1);	
// }

char	*ft_bchar(char *var, char c)
{
	int		i;
	char	*key;

	i = 0;
	while (var[i] != c)
		i++;
	key = ft_calloc(i + 1, 0);
	i = 0;
	while (var[i] != c)
	{
		key[i] = var[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

char	**dupe_env(char **envp)
{
	int		i;
	t_env	**new_env;
	t_env	*actual;

	i = 0;
	while(envp[i])
		i++;
	new_env = calloc(i + 1, 1);
	actual = *new_env;
	i = 0;
	while (envp[i])
	{
		actual->key = ft_bchar(envp[i], '=');
		actual->content = ft_strdup(ft_strchr(envp[i], '=') + 1);
		i++;
		actual = actual->next;
	}
	actual->next = NULL
	return (new_env);
}

int	main(int ac, char **av, char** envp)
{
	t_env	**cpenv;

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