/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_list_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:18:56 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/05 23:47:31 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	modify_list_token(t_token **tok_list)
{
	int		i;
	t_token	*tmp;

	i = 0;
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
	return (1);
}

void	modify_type_tok(t_token *tmp)
{
	enum e_tok	file;

	file = 0;
	if (tmp->type_tok == REDIR_IN)
		file = INFILE;
	else if (tmp->type_tok == REDIR_OUT)
		file = OUTFILE;
	else if (tmp->type_tok == HEREDOC)
		file = HEREDOC_F;
	else if (tmp->type_tok == APPEND)
		file = APPEND_F;
	if (tmp->next && tmp->next->type_tok == ARG)
		tmp->next->type_tok = file;
}
