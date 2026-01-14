/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:35 by smedenec          #+#    #+#             */
/*   Updated: 2025/12/23 17:24:00 by smedenec         ###   ########.fr       */
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

// list

typedef struct s_node
{
	char			**cmd;
	char			**infile;
	char			**outfile;
	char			**heredoc;
	struct s_node	*next;
}	t_node;

// main

int	iterate_input(t_token **list, char *input);
int	parsing(char *input);

#endif
