/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:51:45 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/07 16:08:18 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_tab_elem(char **tab, int index)
{
	int	i;

	if (!tab || index < 0)
		return;

	if (!tab[index])
		return;

	free(tab[index]);

	i = index;
	while (tab[i + 1])
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = NULL;
}

int	check_unset_arg(char *arg)
{
	int	i;

	i = 1;
	if (ft_isalpha(arg[0]) == 0 && arg[0] != '_')
		return (1);
	while (arg[i])
	{
		if (ft_isalpha(arg[i]) == 0 && ft_isalnum(arg[i]) == 0 && arg[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

char	**unset_one(char **envp, char *unset)
{
	int		i;
	int		j;

	i = 0;
	while (envp[i])
	{	
		j = 0;
		while (envp[i][j] != '=')
			j++;
		if (strncmp(unset, envp[i], j) == 0)
		{
			remove_tab_elem(envp, i);
			return (envp);
		}
		i++;
	}
	return (envp);
}

void	bi_unset(char **envp, char **cmd)
{
		int	i;

	i = 0;
	while (cmd[++i])
	{
		if (check_unset_arg(cmd[i]) == 1)
			printf("unset: '%s': not a valid identifier", cmd[i]);
		else
			export_one(envp, cmd[i]);
	}
}