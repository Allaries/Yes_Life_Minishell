/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 22:36:20 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/27 20:38:08 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	printf ("fdhere == %i\n", fdhere);
	if (fdhere == -1)
	{
		printf("%s: No such file or directory", hname);
		return (fdhere);
	}
	// unlink(hname);
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
	printf ("append = %i\n", fdred);
	if (fdred == -1)
		printf("%s: No such file or directory", rname);
	return (fdred);
}

int	infile_init(char *rname)
{
	int		fdred;
	
	fdred = open(rname, O_RDONLY);
	printf ("infile = %i\n", fdred);
	if (fdred == -1)
		printf("%s: No such file or directory", rname);
	return (fdred);
}

int	outfile_init(char *rname)
{
	int		fdred;
	
	fdred = open(rname, O_CREAT | O_TRUNC | O_WRONLY | O_APPEND, 0644);
	printf ("outfile = %i\n", fdred);
	if (fdred == -1)
		printf("%s: No such file or directory", rname);
	return (fdred);
}

int get_infd(t_file **filelist)
{
    t_file  *temp;
    int     fd;
    int     tmp;

	temp = *filelist;
	fd = 0;
	tmp = 0;
    while (temp)
    {
        if (temp->type == HEREDOC_F)
        {
            tmp = heredoc_init(temp->name);
            if (tmp < 0)
            	return (-1);
        	close(tmp);
            tmp = open(temp->name, O_RDONLY);
			unlink(temp->name);
            if (tmp < 0)
            	return (-1);
        }
        if (temp->type == INFILE)
        {
            tmp = infile_init(temp->name);
            if (tmp < 0)
                return (-1);
        }
        fd = tmp;
        temp = temp->next;
    }
    return (fd);
}


int	get_outfd(t_file **filelist)
{
	t_file	*temp;
	int		fd;
	int		tmp;
	
	fd = 1;
	tmp = 1;
	temp = *filelist;
	while ( temp )
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

void	get_fd(t_cmd *cmd)
{
	if (cmd->filelist == NULL)
	{
		cmd->infd = 0;
		cmd->outfd = 1;
		return ;
	}
	cmd->infd = get_infd(cmd->filelist);
	cmd->outfd = get_outfd(cmd->filelist);
	fprintf (stderr, "in : %i, out : %i\n",cmd->infd, cmd->outfd);
	return ;
}
