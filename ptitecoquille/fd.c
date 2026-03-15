/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 22:36:20 by rerichar          #+#    #+#             */
/*   Updated: 2026/03/15 21:21:12 by rerichar         ###   ########.fr       */
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

int	here_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
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

void	heredoc_child(t_data *data, char *delimiter, int *pipefd)
{
	char	*line;

	line = "inoxtag";
	g_sig_status = 1;
	change_signal(data);
	while (line)
	{
		line = get_next_line_omega(STDIN_FILENO);
		if (here_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
		{
			free(line);
			break ;
		}
		write(pipefd[1], line, strlen(line));
		free(line);
	}
	if (!line)
		write(1, "\nwarning: delimited by end-of-file (wanted `EOF')\n", 51);
	close(pipefd[0]);
	close(pipefd[1]);
	thanos_snap_process(data);
	exit(0);
}

int	heredoc_init(t_data *data, char *delimiter)
{
	int	pipefd[2];
	int	status;

	pipe(pipefd);
	data->pid = fork();
	g_sig_status = 3;
	change_signal(data);
	if (data->pid == 0)
		heredoc_child(data, delimiter, pipefd);
	waitpid(data->pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		write(1, "\n", 1);
		data->exit_code = 130;
		close(pipefd[0]);
		close(pipefd[1]);
		return (-1);
	}
	close(pipefd[1]);
	return (pipefd[0]);
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
		else
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

int	first_h_init(t_data *data, t_cmd **cmd)
{
	t_cmd	*tmp;
	t_redir	*redir;

	tmp = *cmd;
	while (tmp)
	{
		redir = tmp->redirs;
		while (redir)
		{
			if (redir->type == HEREDOC_F)
			{
				redir->fd = heredoc_init(data, redir->name);
				if (redir->fd == -1)
					return (0);
			}
			redir = redir->next;
		}
		tmp = tmp->next;
	}
	return (1);
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
