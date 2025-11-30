/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:00:14 by smedenec          #+#    #+#             */
/*   Updated: 2025/11/30 19:14:18 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*create_list(char *str_stdint)
{
	t_list	*prev_list;
	char	*cmd;
	char	**infile;
	char	**outfile;


	printf("processing.. : %s\n", str_stdint);
	return (list);
}

t_list	*create_node(const char *cmd, const char **infile, const char **outfile)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if (!node)
		return NULL;
	node->cmd = ft_strdup(cmd);

    node->array1 = malloc(size1 * sizeof(char*));
    node->size1 = size1;

    node->array2 = malloc(size2 * sizeof(char*));
    node->size2 = size2;

    node->next = NULL;
	return (node);
}
