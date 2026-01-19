/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:17:47 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/16 20:24:42 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// # include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "struct.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

int	iterate_input(t_token **list, char *input);
int	parsing(char *input);
//--------------------------------------------------------------//
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
void	bi_env(char **envp);
void	bi_cd(char **cmd, char **envp);
void	bi_pwd(void);
void	bi_echo(char **cmd);
void	bi_export(char **cmd, char **envp);
void	bi_unset(char **envp, char **cmd);
int		check_bi(char **cmd);

#endif
