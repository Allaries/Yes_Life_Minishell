/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:35 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/09 18:42:26 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

// token

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

// cmd

enum type_file {
	INFILE = 1,
	OUTFILE = 2,
	HEREDOC_F = 3,
	APPEND_F = 4
};

typedef struct s_file
{
	int				fd;
	char			*name;
	enum type_file	type;
	struct s_file	*next;
}	t_file;

typedef struct s_cmd
{
	char			**args;
	t_file			*filelist;
	struct s_cmd	*next;
}	t_cmd;

// main

int	iterate_input(t_token **list, char *input);
int	parsing(char *input);

#endif
