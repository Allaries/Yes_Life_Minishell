/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remi <remi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:10:06 by remi              #+#    #+#             */
/*   Updated: 2026/03/22 18:06:46 by remi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void	close_heredoc(t_data *data, int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
	close_other_here(data);
	thanos_snap_process(data);
}

void	print_stderr(char *toprint, int mod)
{
	if (mod == 1)
		write (2, "command not found : ", 21);
	if (mod == 2)
		write (2, "cd : no such file or directory : ", 33);
	write (2, toprint, (ft_strlen(toprint) + 1));
	write (2, "\n", 1);
}
