/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_file_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:18:56 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/13 06:42:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	define_file_token(t_token **tok_list)
{
	t_token	*tmp;

	tmp = NULL;
	tmp = *tok_list;
	while (tmp)
	{
		if (tmp->type_tok == REDIR_IN || tmp->type_tok == REDIR_OUT
			|| tmp->type_tok == HEREDOC || tmp->type_tok == APPEND)
		{
			modify_type_tok(tmp);
			tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
}

void	modify_type_tok(t_token *tok_list)
{
	enum e_tok	file;

	file = 0;
	if (tok_list->type_tok == REDIR_IN)
		file = INFILE;
	else if (tok_list->type_tok == REDIR_OUT)
		file = OUTFILE;
	else if (tok_list->type_tok == HEREDOC)
		file = HEREDOC_F;
	else if (tok_list->type_tok == APPEND)
		file = APPEND_F;
	if (tok_list->next && tok_list->next->type_tok == ARG)
		tok_list->next->type_tok = file;
}
