/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:00:14 by smedenec          #+#    #+#             */
/*   Updated: 2025/12/14 00:44:30 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	len_file(const char **file, int len)
// {
// 	len = 0;
// 	while (file && (file[len] != NULL))
// 		len++;
// 	return (len);
// }

// t_list	*copy_infile(t_list *node, char **infile, int len_infile)
// {
// 	int	i;

// 	i = 0;
// 	node->infile = malloc(len_infile * sizeof(char *));
// 	if (!node->infile)
// 	{
// 		free(node->cmd);
// 		free(node);
// 		return (NULL);
// 	}
// 	while (i < len_infile)
// 	{
// 		node->infile[i] = ft_strdup(infile[i]);
// 		if (!node->infile[i])
// 		{
// 			while (--i >= 0)
// 				free(node->infile[i]);
// 			free(node->infile);
// 			free(node->cmd);
// 			free(node);
// 			return (NULL);
// 		}
// 		i++;
// 	}
// 	return (node);
// }

// t_list	*copy_outfile(t_list *node, char **outfile, int len_outfile)
// {
// 	int	i;

// 	i = 0;
// 	node->outfile = malloc(len_outfile * sizeof(char *));
// 	if (!node->outfile)
// 	{
// 		free(node->cmd);
// 		free(node);
// 		return (NULL);
// 	}
// 	while (i < len_outfile)
// 	{
// 		node->outfile[i] = ft_strdup(outfile[i]);
// 		if (!node->outfile[i])
// 		{
// 			while (--i >= 0)
// 				free(node->outfile[i]);
// 			free(node->outfile);
// 			free(node->cmd);
// 			free(node);
// 			return (NULL);
// 		}
// 		i++;
// 	}
// 	return (node);
// }

// t_list	*add_file(t_list *node, char **infile, char **outfile)
// {
// 	int		len_infile;
// 	int		len_outfile;

// 	len_infile = len_file(infile, len_infile);
// 	len_outfile = len_file(outfile, len_outfile);
// 	if (infile && len_infile)
// 		if (!copy_infile(&node, infile, len_infile))
// 			return (NULL);
// 	else
// 		node->infile = NULL;
// 	if (outfile && len_outfile)
// 		if (copy_outfile(&node, outfile, len_outfile))
// 			return (NULL);
// 	else
// 		node->outfile = NULL;
// 	return (node);
// }
