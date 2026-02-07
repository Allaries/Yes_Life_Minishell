/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:41:30 by rerichar          #+#    #+#             */
/*   Updated: 2026/02/07 01:02:16 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

typedef struct s_redir
{
    int                fd;
    char            *name;
    enum e_tok        type;
    struct s_redir    *next;
}    t_redir;

typedef struct t_cmd
{
    char			**args;
    t_redir			**filelist;
	char			*path;
	int				infd;
	int				outfd;
	int				pid;
	int				built_in;
	struct t_cmd	*next;
}    t_cmd;

typedef struct s_data {
	char	**envp;
	t_cmd	**cmd;
	int		*pid;
	int		oldpipe[2];
	int		newpipe[2];
}	t_data;
