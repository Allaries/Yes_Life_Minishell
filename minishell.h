/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:17:47 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/27 14:08:08 by smedenec         ###   ########.fr       */
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
int				build_cmd(char *input);

// check_input
int				check_input(char *input);

// check_quote
int				check_quote(char *input);
int				is_pair(char *input);
int				find_second_quote(char *input, char q, int *i);

// build_list_token
int				build_list_token(t_token **tok_list, char *input);
int				iterate_input(t_token **list, char *input);

// build_word
int				create_word(t_token **tok_list, char *input, int *i);
int				iterate_word(char *input, char *word, int *i);
int				is_word(char *input, int *i, char *q);

// token
int				add_tok_in_list(t_token **tok_list, char **word);
t_token			*create_token(char *word, enum e_type_tok type);

// token_utils
int				is_tok(char *input, int start, int len);
enum e_type_tok	which_type(char *word);

// verify_list_token
int				verify_list_token(t_token **tok_list);
int				is_front_token(t_token **tok_list);
int				is_separated_token(t_token **tok_list);

// utils
int				is_space(char c);
int				ft_strcmp_safe(const char *s1, const char *s2);
char			*ft_strduplicate(const char *s);

// free
void			free_list_word(t_token **list, char **word);

#endif
