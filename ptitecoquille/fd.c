/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remi <remi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 22:36:20 by rerichar          #+#    #+#             */
/*   Updated: 2026/03/22 18:06:31 by remi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#include <unistd.h>
#include <stdlib.h>

static int	open_infile(t_redir *node)
{
	if (node->type == HEREDOC_F)
		return (node->fd);
	if (node->type == INFILE)
		return (infile_init(node->name));
	return (-2);
}

int	get_infd(t_redir *filelist)
{
	t_redir	*temp;
	int		fd;
	int		tmp;

	fd = -1;
	temp = filelist;
	while (temp)
	{
		tmp = open_infile(temp);
		if (tmp == -2)
		{
			temp = temp->next;
			continue ;
		}
		if (tmp < 0)
			return (-1);
		if (fd >= 0 && fd != tmp)
			close(fd);
		fd = tmp;
		temp = temp->next;
	}
	if (fd == -1 || fd == -2)
		return (0);
	return (fd);
}

static int	open_outfile(t_redir *node)
{
	if (node->type == OUTFILE)
		return (outfile_init(node->name));
	if (node->type == APPEND_F)
		return (append_init(node->name));
	return (-2);
}

int	get_outfd(t_redir *filelist)
{
	t_redir	*temp;
	int		fd;
	int		tmp;

	fd = -1;
	temp = filelist;
	while (temp)
	{
		tmp = open_outfile(temp);
		if (tmp == -2)
		{
			temp = temp->next;
			continue ;
		}
		if (tmp < 0)
			return (-1);
		if (fd >= 0 && fd != tmp)
			close(fd);
		fd = tmp;
		temp = temp->next;
	}
	if (fd == -1 || fd == -2)
		return (1);
	return (fd);
}

int	get_fd(t_cmd *cmd)
{
	if (cmd->redirs == NULL)
	{
		cmd->infd = 0;
		cmd->outfd = 1;
		return (1);
	}
	cmd->infd = get_infd(cmd->redirs);
	cmd->outfd = get_outfd(cmd->redirs);
	if (cmd->infd == -1 || cmd->outfd == -1)
	{
		if (cmd->infd != -1 && cmd->infd != 0)
			close (cmd->infd);
		if (cmd->outfd != -1 && cmd->outfd != 1)
			close (cmd->outfd);
		return (0);
	}
	return (1);
}
