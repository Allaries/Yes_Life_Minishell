/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:17:47 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/05 16:26:03 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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
int		*env_already_exist(char **envp, char *var);
char	**dupe_env(char **envp);
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