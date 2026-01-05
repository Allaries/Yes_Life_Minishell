/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:16:03 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/05 16:43:46 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	relocate_env_elem(char **env, int index, char *var)
{
	int	i;

	if (!env || index < 0)
		return;
	if (!env[index])
		return;
	free(env[index]);
	i = index;
	while (env[i + 1])
	{
		env[i] = env[i + 1];
		i++;
	}
	env[i] = ft_strdup(var);
}


char	**dupe_env(char **envp)
{
	int		i;
	char	**new_env;

	i = 0;
	while(envp[i])
		i++;
	new_env = calloc((i + 1) * sizeof(char *), 1);
	if (!new_env)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		new_env[i] = ft_strdup(envp[i]);
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}
