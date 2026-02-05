/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:17:47 by rerichar          #+#    #+#             */
/*   Updated: 2026/02/05 17:41:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
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

// build_struct_cmd
int				parsing(char *input);

// build_list_cmd
int				build_list_cmd(t_cmd **cmd_list, t_token **tok_list);
int				fill_list_cmd(t_cmd	**cmd_list, t_token **tok_list);

// build_list_token
int				build_list_token(char *input, t_token **tok_list);
int				fill_list_token(char *input, t_token **tok_list);

// check_input
int				check_input(char *input);

// check_quote
int				check_quote(char *input);
int				is_pair(char *input);
int				find_second_quote(char *input, char q, int *i);

// word
t_word			*init_word(int size);
int				parse_word(char *input, t_word **word, int *i);
int             skip_quote(char *input, t_word *word, int *i);
int				can_extend(char *input, t_word *word, int *i);

// word_utils
void	        first_one(char *input, t_word *word, int *i);
void	        skip_one(char *input, t_word *word, int *i, char q);
char            which_quote(t_word *word);
int				add_char_in_word(t_word *word, char char_buf);
int				realloc_word(t_word *word);

// token
int				add_tok_in_list(t_token **tok_list, t_word **word);
t_token			*create_token(char *buf, enum e_tok type);

// token_utils
int				is_tok(char *input, int start, int len);
enum e_tok		which_type(char *buf);

// verify_list_token
int				verify_list_token(t_token **tok_list);
int				is_front_token(t_token **tok_list);
int				is_separated_token(t_token **tok_list);

// utils
int				is_space(char c);
int				ft_strcmp_safe(const char *s1, const char *s2);
char			*ft_strduplicate(const char *s);

// free
void			free_all(t_token **list, t_word **word);
void			free_list_token(t_token **list);
void			free_token(t_token *tok);
void			free_word(t_word **word);

#endif
