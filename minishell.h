/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:17:47 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/22 14:56:37 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
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

// create_cmd
int		create_cmd(char *input);

// check_input
int		check_input(char *input);

// check_quote
int		check_quote(char *input);

// check_token
int		check_token(t_token **tok_list, char *input);
int		iterate_input(t_token **list, char *input);
int		is_tok(char *input, int start, int len);

// create_token
int		create_word(t_token **tok_list, char *input, int *i);
t_token	*create_token(char *word, enum e_type_tok type);
int		add_tok_in_list(t_token **tok_list, char **word);
enum	e_type_tok	which_type(char *word);

// utils
int		is_space(char c);
int		ft_strcmp_safe(const char *s1, const char *s2);
char	*ft_strduplicate(const char *s);

// free
void	free_list_word(t_token **list, char **word);







int		is_tok(char *input, int start, int len);

int		check_quote(char *input);

#endif
