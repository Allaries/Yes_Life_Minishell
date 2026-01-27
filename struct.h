/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/27 15:14:54 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// to compile : valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ./minishell

#ifndef STRUCT_H
# define STRUCT_H

enum e_tok {
	PIPE = 1,
	REDIR_IN = 2,
	REDIR_OUT = 3,
	HEREDOC = 4,
	APPEND = 5,
	CMD = 6,
	ARG = 7,
	CQUOI = 8
};

enum e_quote {
	NO_QUOTE = 0,
	SINGLE_QUOTE = 1,
	DOUBLE_QUOTE = 2
};

typedef struct s_token
{
	char			*word;
	enum e_tok		type_tok;
	enum e_quote	type_quote;
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

#endif
