/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 22:36:20 by rerichar          #+#    #+#             */
/*   Updated: 2026/02/21 22:32:24 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	here_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] != '\n')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if ((s1[i] == '\n' || s1[i] == '\0') && s2[i] == '\0')
		return (0);
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int heredoc_init(char *delimiter)
{
	int pipefd[2];
	char *line;

	pipe(pipefd);

	while ((line = get_next_line(STDIN_FILENO)))
	{
		if (here_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
		{
			free(line);
			break;
		}
		write(pipefd[1], line, strlen(line));
		free(line);
		line = NULL;
	}
	close(pipefd[1]);
	return pipefd[0];
}


int	append_init(char *rname)
{
	int		fdred;

	fdred = open(rname, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fdred == -1)
		printf("No such file or directory : %s\n", rname);
	return (fdred);
}

int	infile_init(char *rname)
{
	int		fdred;

	fdred = open(rname, O_RDONLY);
	if (fdred == -1)
		printf("No such file or directory : %s\n", rname);
	return (fdred);
}

int	outfile_init(char *rname)
{
	int		fdred;

	fdred = open(rname, O_CREAT | O_TRUNC | O_WRONLY | O_APPEND, 0644);
	if (fdred == -1)
		printf("No such file or directory : %s\n", rname);
	return (fdred);
}

int get_infd(t_redir *filelist)
{
	t_redir  *temp;
	int     fd;
	int     tmp;

	temp = filelist;
	fd = 0;
	tmp = 0;
	while (temp)
	{
		if (temp->type == HEREDOC_F)
			tmp = temp->fd;
		if (temp->type == INFILE)
			tmp = infile_init(temp->name);
		if (tmp < 0)
		{
			if (fd != 0)
				close(fd);
			return (-1);
		}
		if (fd != 0)
			close(fd);
		fd = tmp;
		temp = temp->next;
	}
	return (fd);
}


int	get_outfd(t_redir *filelist)
{
	t_redir	*temp;
	int		fd;
	int		tmp;

	fd = 1;
	tmp = 1;
	temp = filelist;
	while (temp)
	{
		if (temp->type == OUTFILE)
			tmp = outfile_init(temp->name);
		if (temp->type == APPEND_F)
			tmp = append_init(temp->name);
		if (tmp < 0)
		{
			if (fd != 1)
				close(fd);
			return (-1);
		}
		if (fd != 1)
			close(fd);
		fd = tmp;
		temp = temp->next;
	}
	return (fd);
}

int	first_h_init(t_cmd **cmd)
{
	t_cmd *tmp;
	t_redir *redir;

	tmp = *cmd;
	while (tmp)
	{
		redir = tmp->redirs;
		while (redir)
		{
			if (redir->type == HEREDOC_F)
			{
				redir->fd = heredoc_init(redir->name);
			}
			redir = redir->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	close_useless(int infd, int outfd, t_redir *redir)
{
	t_redir	*tmp;

	tmp = redir;
	while (tmp)
	{
		if (tmp->fd != -1 && tmp->fd != infd && tmp->fd != outfd)
			close (tmp->fd);
		tmp = tmp->next;
	}
	
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
	// close_useless(cmd->infd, cmd->outfd, cmd->redirs);
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
