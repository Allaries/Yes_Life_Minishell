/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:41:30 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/14 20:41:40 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum type_file {
    INFILE = 1,
    OUTFILE = 2,
    HEREDOC_F = 3,
    APPEND_F = 4
};

typedef struct t_file
{
    int				fd;
    char			*name;
    enum type_file	type;
    struct s_file	*next;
}    t_file;

typedef struct t_cmd
{
    char			**args;
    t_file			**filelist;
	int				infd;
	int				outfd;
	int				built_in;
	struct s_cmd	*next;
}    t_cmd;

typedef struct t_data {
	char	*path;
	char	**args;
	char	*cmd;
	char	*flags;
	char	**envp;
	int		*pid;
	int		oldpipe[2];
	int		newpipe[2];
	t_cmd	**cmd;
}	t_data;
