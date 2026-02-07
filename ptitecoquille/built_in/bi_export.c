/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:49:53 by rerichar          #+#    #+#             */
/*   Updated: 2026/02/07 04:21:12 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**export_new_var(char **envp, char *export)
{
	int		i;
	char	**new_env;

	i = 0;
	while (envp[i])
		i++;
	new_env = ft_calloc(sizeof(char *) * (i + 2), 1);
	if (!new_env)
		return (printf("malloc error\n"), envp);
	i = 0;
	while (envp[i])
	{
		new_env[i] = ft_strdup(envp[i]);
		i++;
	}
	free_tab(envp);
	new_env[i] = ft_strdup(export);
	new_env[++i] = NULL;
	return (new_env);
}

void	export_one(t_data *data, char *export)
{
	int		i;
	int		j;

	i = 0;
	while (data->envp[i])
	{	
		j = 0;
		while (data->envp[i][j] != '=')
			j++;
		if (strncmp(export, data->envp[i], j + 1) == 0)
		{
			free (data->envp[i]);
			data->envp[i] = ft_strdup(export);
			return ;
		}
		i++;
	}
	data->envp = export_new_var(data->envp, export);
	return ;
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

void	bi_export(t_data *data, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[++i])
	{
		if (check_export_arg(cmd->args[i]) == 1)
			printf("export: `%s': not a valid identifier", cmd->args[i]);
		else
			export_one(data, cmd->args[i]);
	}
	if (i == 1)
		bi_env(data->envp);
}
