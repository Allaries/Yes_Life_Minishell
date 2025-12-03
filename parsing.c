/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:00:14 by smedenec          #+#    #+#             */
/*   Updated: 2025/12/03 16:59:08 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	copy_infile(t_list *node, const char **infile, int len_infile)
{
	int	i;

	i = 0;
	node->infile = malloc(len_infile * sizeof(char *));
	if
}
t_list	copy_outfile(t_list *node, const char **outfile, int len_outfile)
{
	node->outfile = malloc(len_outfile * sizeof(char *));
}

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
	t_list	*node;
	int		len_infile;
	int		len_outfile;

	len_infile = 0;
	len_outfile = 0;
	while (infile && (infile[len_infile] != NULL))
		len_infile++;
	while (outfile && (outfile[len_outfile] != NULL))
		len_outfile++;
	node = malloc(sizeof(t_list));
	if (!node)
		return NULL;
	node->cmd = ft_strdup(cmd);
	if (infile && len_infile)
		node = copy_in_out_file(&node, infile, len_infile);
	if (outfile && len_outfile)
		node = copy_in_out_file(&node, outfile, len_outfile);
	return (node);
}
