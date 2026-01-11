/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:35 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/11 19:09:01 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

// to compile : valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ./minishell

// token

enum e_type_tok {
	PIPE = 1,
	REDIR_IN = 2,
	REDIR_OUT = 3,
	HEREDOC = 4,
	APPEND = 5,
	CMD = 6,
	ARG = 7,
	CQUOI = 8
};

typedef struct s_token
{
	char			*word;
	enum e_type_tok	type;
	struct s_token	*next;
}	t_token;

// cmd

enum e_type_file {
	INFILE = 11,
	OUTFILE = 12,
	HEREDOC_F = 13,
	APPEND_F = 14
};

typedef struct s_redir
{
	int					fd;
	char				*name;
	enum e_type_file	type;
	struct s_redir		*next;
}	t_redir;

typedef struct s_cmd
{
	char			**args;
	t_redir			*redirs;
	struct s_cmd	*next;
}	t_cmd;

// main

int	iterate_input(t_token **list, char *input);
int	parsing(char *input);

#endif
