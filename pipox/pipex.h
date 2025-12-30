/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 01:36:50 by rerichar          #+#    #+#             */
/*   Updated: 2025/12/21 02:29:23 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// # include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h> 
# include <sys/wait.h>

typedef struct t_data {
	int		heredoc;
	int		nb_of_cmd;
	char	*path;
	char	**args;
	char	*cmd;
	char	*flags;
	char	**envp;
	int		infd;
	int		outfd;
	int		*pid;
	int		oldpipe[2];
	int		newpipe[2];
}	t_data;

void	ft_strcat(char *dest, const char *src);
int		def_path(t_data *data);
void	def_arg(char *cmd, t_data *data);
char	*slashcmd(char *cmd, char *path);
void	free_tab(char **tab);
int		check_fd(char **argv, t_data *data);
void	free_struct(t_data *data);
int		close_all(t_data *data);
void	error(int type);
int		exec_pipex(char **argv, t_data *data);
int		execute_child(char **argv, t_data *data, int i);
int		double_out_init(char *rname);
int		single_in_init(char *rname);
int		single_out_init(char *rname);
int		heredoc_init(char *hname);


#endif