/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 22:36:20 by rerichar          #+#    #+#             */
/*   Updated: 2025/12/18 01:28:18 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

	fdhere = open(hname, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	unlink(hname);
	while (1)
	{
		str = get_next_line(1);
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
	return (0);
}

int	double_out_init(char *rname)
{
	int		fdred;
	
	fdred = open(rname, O_CREAT | O_WRONLY | O_APPEND, 0644);
	return (fdred);
}

int	single_in_init(char *rname)
{
	int		fdred;
	
	fdred = open(rname, O_RDONLY);
	return (fdred);
}

int	single_out_init(char *rname)
{
	int		fdred;
	
	fdred = open(rname, O_TRUNC | O_WRONLY | O_APPEND, 0644);
	return (fdred);
}
