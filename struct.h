/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/05 23:52:08 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

// token

enum e_tok {
	VOID,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HEREDOC,
	APPEND,
	INFILE,
	OUTFILE,
	HEREDOC_F,
	APPEND_F,
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

typedef struct s_redir
{
	int				fd;
	char			*name;
	enum e_tok		type;
	struct s_redir	*next;
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
}	t_cmd;

#endif
