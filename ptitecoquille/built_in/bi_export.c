/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:49:53 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/14 20:24:01 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**export_new_var(char **envp, char *export)
{
	int		i;
	char	**new_env;

	i = 0;
	while (envp[i])
		i++;
	new_env = ft_calloc(sizeof(char *) * (i + 2), 1);
	if (!new_env)
		return (printf("export error\n"), envp);
	i = 0;
	while (envp[i])
	{
		new_env[i] = envp[i];
		i++;
	}
	new_env[i] = ft_strdup(export);
	new_env[++i] = NULL;
	return (new_env);
}

char	**export_one(char **envp, char *export)
{
	int		i;
	int		j;

	i = 0;
	while (envp[i])
	{	
		j = 0;
		while (envp[i][j] != '=')
			j++;
		if (strncmp(export, envp[i], j) == 0)
		{
			free (envp[i]);
			envp[i] = ft_strdup(export);
			return (envp);
		}
		i++;
	}
	envp = export_new_var(envp, export);
	return (envp);
}

int	check_export_arg(char *arg)
{
	int	i;

	i = 1;
	if (ft_isalpha(arg[0]) == 0 && arg[0] != '_')
		return (1);
	while (arg[i] && arg[i] != '=')
	{
		if (ft_isalpha(arg[i]) == 0 && ft_isalnum(arg[i]) == 0 && arg[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

void	bi_export(char **cmd, char **envp)
{
	int	i;

	i = 0;
	while (cmd[++i])
	{
		if (check_export_arg(cmd[i]) == 1)
			printf("export: `%s': not a valid identifier", cmd[i]);
		else
			export_one(envp, cmd[i]);
	}
	if (i = 1)
		bi_env(envp);
}
