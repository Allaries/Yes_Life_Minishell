/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 22:36:20 by rerichar          #+#    #+#             */
/*   Updated: 2026/02/17 19:56:41 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	here_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && n > i)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			if (s1[i] == '\n' && s2[i] == '\0')
				return (0);
			else
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

int	heredoc_init(char *hname)
{
	int		fdhere;
	char	*str;

	fdhere = open(hname, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fdhere == -1)
	{
		printf("No such file or directory : %s\n", hname);
		return (fdhere);
	}
	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (here_strncmp(str, hname, ft_strlen(hname) + 1) != 0)
		{
			write(fdhere, str, ft_strlen(str));
			free(str);
		}
		else
			return (free(str), fdhere);
	}
	if (str)
		free(str);
	return (fdhere);
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
        {
			printf ("%i\n", temp->fd);
            tmp = temp->fd;
            if (tmp < 0)
            	return (-1);

        }
        if (temp->type == INFILE)
            tmp = infile_init(temp->name);
		if (tmp < 0)
		{
			if (fd != 0)
				close(fd);
			return (-1);
		}
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
				close (redir->fd);
				open (redir->name, O_RDONLY);
			}
			redir = redir->next;
		}
		tmp = tmp->next;
	}
	return (0);
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
