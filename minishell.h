/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:17:47 by rerichar          #+#    #+#             */
/*   Updated: 2026/02/18 04:39:33 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// # include "../libft/libft.h"
# include "gnl/get_next_line.h"
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

///////////////////////////////////////////////
// parsing
int			parsing(char *input, t_data *data);
t_input		*init_input(int size);
// list_cmd
int			build_list_cmd(t_cmd **cmd_list, t_token **tok_list);
int			fill_list_cmd(t_cmd	**cmd_list, t_token **tok_list);
// list_token
int			build_list_token(char *input, t_token **tok_list);
///////////////////////////////////////////////
// cmd
int			add_cmd_in_list(t_cmd **cmd_list, t_token *tok_list);
t_cmd		*create_cmd(t_token *tok_list);
// args
int			fill_args(char ***args, t_token *tok_list);
int			argslen(t_token *tok_list);
// redir
int			fill_list_redir(t_redir **redir_list, t_token *tok_list);
int			add_redir_in_list(t_redir **redir_list, t_token *tok_list);
t_redir		*create_redir(t_token *tok_list);
///////////////////////////////////////////////
// check_quote
int			check_quote(char *input);
int			is_pair(char *input);
int			find_second_quote(char *input, char q, int *i);
///////////////////////////////////////////////
// expend
int			expend_input(char *input, t_input **new_input);
int			is_quote(char *input, t_input *new_input, int *i);
int			is_expend(char *input, t_input *new_input, int *i);
void		go_expend(char *input, t_input *new_input, int *i);
// expend_utils
int			which_quote_inp(t_input *new_input);
int			add_char_in_input(t_input *new_input, char c);
int			realloc_input(t_input *new_input);
void		toggle_quote_inp(char *input, t_input *new_input, int *i);
///////////////////////////////////////////////
// verify_list_token
int			verify_list_token(t_token **tok_list);
int			is_good_pipe(t_token *tok);
int			is_there_file(t_token *tok);
// define_file_token
int			define_file_token(t_token **tok_list);
void		modify_type_tok(t_token *tmp);
///////////////////////////////////////////////
// word
t_word		*init_word(int size);
int			parse_word(char *input, t_word **word, int *i);
int			skip_quote(char *input, t_word *word, int *i);
int			continue_word(char *input, t_word *word, int *i);
int			is_tok(char *input, t_word *word, int i);
// word_utils
int			which_quote_w(t_word *word);
int			add_char_in_word(t_word *word, char c);
int			realloc_word(t_word *word);
int			char_is_a_quote(char *input, int i);
void		toggle_quote_w(char *input, t_word *word, int *i);
// token
int			fill_list_token(char *input, t_token **tok_list);
int			add_tok_in_list(t_token **tok_list, t_word **word);
t_token		*create_token(char *buf, enum e_tok type);
enum e_tok	which_type(char *buf, int was_quote);
int			char_is_a_token(char c);
///////////////////////////////////////////////
// utils
int			is_space(char c);
int			ft_strcmp_safe(const char *s1, const char *s2);
char		*ft_strduplicate(const char *s);
char		*ft_realloc(void *ptr, size_t new_size);
char		*type_to_str(enum e_tok type);
// free
void		free_all(t_token **list, t_word **word);
void		free_list_token(t_token **list);
void		free_list_cmd(t_cmd **list);
void		free_list_redir(t_redir **list);
// free_node
void		free_token(t_token *tok);
void		free_word(t_word **word);
void		free_input(t_input **new_input);
void		free_cmd(t_cmd *cmd);
void		free_redir(t_redir *redir);
///////////////////////////////////////////////

void	ft_strcat(char *dest, const char *src);
int		*env_already_exist(char **envp, char *var);
char	**dupe_env(char **envp);
int		def_path(t_data *data, t_cmd *cmd);
void	def_arg(char *cmd, t_data *data);
char	*slashcmd(char *cmd, char *path);
void	free_tab(char **tab);
int		check_fd(char **argv, t_data *data);
void	free_struct(t_data *data);
int		close_all(t_data *data, t_cmd *cmd);
int		exec_pipex(t_data *data, t_cmd **cmd);
int		execute_child(t_data *data, t_cmd *herecmd, int i);
int		get_fd(t_cmd *cmd);
void	check_bi(t_cmd *cmd);
void	exec_single_bi(int mod, t_data *data, t_cmd *cmd);
void	bi_exit(t_data *data);
void	bi_env(char **envp);
void	bi_cd(char **cmd, char **envp);
void	bi_pwd(void);
void	bi_echo(char **cmd);
void	bi_export(t_data *data, t_cmd *cmd);
void	export_one(t_data *data, char *export);
void	bi_unset(t_data *data, t_cmd *cmd);
void	thanos_snap_process(t_data *data);
void	free_cmd_struct(t_cmd **cmd);

#endif
