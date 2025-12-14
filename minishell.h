/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:35 by smedenec          #+#    #+#             */
/*   Updated: 2025/12/14 00:44:52 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

// list
typedef struct t_list
{
	char			**cmd;
	char			**infile;
	char			**outfile;
	int				*heredoc; // au faite non
	struct t_list	*next;
}	t_list;

// main
void	*error_free_all(t_list **node);

// send_list
// t_list	*send_list(char *str_stdint);
// t_list	*create_node(char **cmd, char **infile, char **outfile);

// add_file
// t_list	*add_file(t_list *node, char **infile, char **outfile);
// t_list	*copy_outfile(t_list *node, char **outfile, int len_outfile);
// t_list	*copy_infile(t_list *node, char **infile, int len_infile);
// int		len_file(const char **file, int len);

#endif
