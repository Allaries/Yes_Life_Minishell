/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:49:53 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/05 18:10:48 by rerichar         ###   ########.fr       */
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
	i = 0;
	while (envp[i])
	{
		new_env[i] = envp[i];
		i++;
	}
	new_env[i] = export;
	new_env[++i] = NULL;
	free_tab(envp);
	return (new_env);
}

char	**bi_export(char **envp, char *export)
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
