/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:35 by smedenec          #+#    #+#             */
/*   Updated: 2025/12/18 08:43:58 by smedenec         ###   ########.fr       */
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
	PIPE,
	ARG,
	INFILE,
	OUTFILE,
	SINGLE_R,
	SINGLE_L,
	DOUBLE_R,
	DOUBLE_L
};

typedef struct s_token
{
	char			*tok;
	enum type_tok	type;
	struct s_token	*next;
}	t_token;

// list

typedef struct s_node
{
	char			**cmd;
	char			**infile;
	char			**outfile;
	struct s_node	*next;
}	t_node;

// main

void	separate_word(char *input);
void	parsing(char *input);

#endif
