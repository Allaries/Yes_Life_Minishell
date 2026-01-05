/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:51:45 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/05 18:23:53 by rerichar         ###   ########.fr       */
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

char	**bi_unset(char **envp, char *unset)
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