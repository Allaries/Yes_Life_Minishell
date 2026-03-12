/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:51:45 by rerichar          #+#    #+#             */
/*   Updated: 2026/03/12 19:22:10 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**remove_tab_elem(char **tab, int index)
{
	int	i;

	if (!tab || index < 0)
		return (NULL);
	if (!tab[index])
		return (NULL);
	free(tab[index]);
	i = index;
	while (tab[i + 1])
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = NULL;
	return (tab);
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

void	unset_one(t_data *data, char *unset)
{
	int		i;
	
	i = 0;
	while (data->envp[i])
	{
		if (strncmp(unset, data->envp[i], ft_strlen(unset)) == 0)
		{
			data->envp = remove_tab_elem(data->envp, i);
			if (data->envp == NULL)
				printf("unset problem");
			return ;
		}
		i++;
	}
	return ;
}

int	bi_unset(t_data *data, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[++i])
	{
		if (check_unset_arg(cmd->args[i]) == 1)
			printf("unset: '%s': not a valid identifier\n", cmd->args[i]);
		else
			unset_one(data, cmd->args[i]);
	}
	return (0);
}