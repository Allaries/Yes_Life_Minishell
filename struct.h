/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:41:30 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/22 13:50:50 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//parsing

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

// exec

typedef struct t_data {
	char	*path;
	char	**args;
	char	*flags;
	char	**envp;
	int		*pid;
	int		oldpipe[2];
	int		newpipe[2];
	t_cmd	**cmd;
}	t_data;
