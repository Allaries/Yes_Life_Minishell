/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 22:36:20 by rerichar          #+#    #+#             */
/*   Updated: 2026/03/20 17:34:55 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#include <unistd.h>
#include <stdlib.h>

static char	*ft_realloc_gnl(char *old, char c, int len)
{
	char	*new;
	int		i;

	new = malloc(len + 2);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = old[i];
		i++;
	}
	new[len] = c;
	new[len + 1] = '\0';
	free(old);
	return (new);
}

char	*get_next_line_omega(int fd)
{
	char	*line;
	char	buf;
	int		r;
	int		len;

	line = NULL;
	len = 0;
	write (0, "> ", 2);
	r = read(fd, &buf, 1);
	while (r > 0)
	{
		line = ft_realloc_gnl(line, buf, len);
		if (!line)
			return (NULL);
		len++;
		if (buf == '\n')
			return (line);
		r = read(fd, &buf, 1);
	}
	if (len > 0)
		return (line);
	free(line);
	return (NULL);
}

int	append_init(char *rname)
{
	int		fdred;

	fdred = open(rname, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fdred == -1)
		perror("open ");
	return (fdred);
}

int	infile_init(char *rname)
{
	int		fdred;

	fdred = open(rname, O_RDONLY);
	if (fdred == -1)
		perror("open ");
	return (fdred);
}

int	outfile_init(char *rname)
{
	int		fdred;

	fdred = open(rname, O_CREAT | O_TRUNC | O_WRONLY | O_APPEND, 0644);
	if (fdred == -1)
		perror("open ");
	return (fdred);
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
		if (temp->type == HEREDOC_F)
			tmp = temp->fd;
		else if (temp->type == INFILE)
			tmp = infile_init(temp->name);
		else {
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
	if (fd == -1)
		return (0);
	return (fd);
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
		if (temp->type == OUTFILE)
			tmp = outfile_init(temp->name);
		else if (temp->type == APPEND_F)
			tmp = append_init(temp->name);
		else {
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
	if (fd == -1)
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
