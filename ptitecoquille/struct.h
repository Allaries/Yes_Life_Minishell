/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:41:30 by rerichar          #+#    #+#             */
/*   Updated: 2026/02/02 21:45:59 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


enum type_tok {
	CMD = 1,
	PIPE = 2,
	ARG = 3,
	REDIR_IN = 4,
	REDIR_OUT = 5,
	HEREDOC = 6,
	APPEND = 7,
	CQUOI = 8
};

typedef struct s_token
{
	char			*word;
	enum type_tok	type;
	struct s_token	*next;
}	t_token;

enum type_file {
    INFILE = 1,
    OUTFILE = 2,
    HEREDOC_F = 3,
    APPEND_F = 4
};

typedef struct t_file
{
    char			*name;
    enum type_file	type;
    struct t_file	*next;
}    t_file;

typedef struct t_cmd
{
    char			**args;
    t_file			**filelist;
	char			*path;
	int				infd;
	int				outfd;
	int				pid;
	int				built_in;
	struct t_cmd	*next;
}    t_cmd;

typedef struct t_data {
	char	**envp;
	t_cmd	**cmd;
	int		*pid;
	int		oldpipe[2];
	int		newpipe[2];
}	t_data;
