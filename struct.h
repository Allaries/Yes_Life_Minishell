/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/05 15:57:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

enum e_tok {
	VOID,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HEREDOC,
	APPEND,
	CMD,
	ARG
};

typedef struct s_word
{
	char	*buf;
	int		in_squote;
	int		in_dquote;
	int		expand;
	int		size;
	int		len;
}	t_word;

typedef struct s_token
{
	char			*word;
	enum e_tok		type_tok;
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
    t_redir			**redirs;
	char			*path;
	int				infd;
	int				outfd;
	int				pid;
	int				built_in;
	struct s_cmd	*next;
}    t_cmd;

#endif
