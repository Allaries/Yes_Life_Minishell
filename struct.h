/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:41:30 by rerichar          #+#    #+#             */
/*   Updated: 2026/02/18 23:13:50 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum e_tok {
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

typedef struct s_input
{
	char	*str;
	int		in_squote;
	int		in_dquote;
	int		size;
	int		len;
}	t_input;

typedef struct s_word
{
	char	*buf;
	int		in_squote;
	int		in_dquote;
	int		was_quote;
	int		was_token;
	int		size;
	int		len;
}	t_word;

typedef struct s_token
{
	char			*word;
	enum e_tok		type_tok;
	struct s_token	*next;
}	t_token;

typedef struct s_redir
{
	int				fd;
	char			*name;
	enum e_tok		type;
	struct s_redir	*next;
}	t_redir;

typedef struct t_cmd
{
	char			**args;
	t_redir			*redirs;
	char			*path;
	int				infd;
	int				outfd;
	int				pid;
	int				built_in;
	int				single_one;
	struct t_cmd	*next;
}	t_cmd;

typedef struct s_data {
	char	**envp;
	t_cmd	**cmd;
	int		exit_code;
	int		pid;
	struct	sigaction sa;
	int		oldpipe[2];
	int		newpipe[2];
}	t_data;
