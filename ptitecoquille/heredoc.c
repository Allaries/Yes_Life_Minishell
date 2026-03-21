/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 21:14:18 by rerichar          #+#    #+#             */
/*   Updated: 2026/03/20 18:45:28 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void	close_other_here(t_data *data)
{
	t_cmd	*cmd;
	t_redir	*redir;

	cmd = *data->cmd;
	while (cmd)
	{
		redir = cmd->redirs;
		while (redir)
		{
			if (redir->type == HEREDOC_F && redir->fd != -1)
				close(redir->fd);
			redir = redir->next;
		}
		cmd = cmd->next;
	}
}

void	heredoc_child(t_data *data, char *delimiter, int *pipefd)
{
	char	*line;
	int		i;

	i = 0;
	change_signal(data, 1);
	while (g_sig_status != SIGINT)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (here_strncmp(line, delimiter, ft_strlen(delimiter) + 1) == 0)
			break ;
		write(pipefd[1], line, strlen(line));
		write(pipefd[1], "\n", 1);
		free(line);
	}
	if (!line)
	{
		if (g_sig_status == SIGINT)
			i = 130;
		else
			write(1, "warning: delimited by end-of-file (wanted `EOF')\n", 50);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	close_other_here(data);
	thanos_snap_process(data);
	exit(i);
}

int	heredoc_init(t_data *data, char *delimiter)
{
	int	pipefd[2];
	int	status;

	pipe(pipefd);
	data->pid = fork();
	change_signal(data, 3);
	if (data->pid == 0)
		heredoc_child(data, delimiter, pipefd);
	waitpid(data->pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
	{
		g_sig_status = 0;
		data->exit_code = 130;
		close(pipefd[0]);
		close(pipefd[1]);
		return (-1);
	}
	close(pipefd[1]);
	return (pipefd[0]);
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
