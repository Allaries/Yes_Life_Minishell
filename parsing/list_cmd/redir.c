/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:53:53 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/10 15:17:18 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	fill_list_redir(t_redir **redir_list, t_token *tok_list)
{
	enum e_tok	t;

	t = 0;
	while (tok_list && tok_list->type_tok != PIPE)
	{
		t = tok_list->type_tok;
		if (t == INFILE || t == OUTFILE || t == HEREDOC_F || t == APPEND_F)
			if (!add_redir_in_list(redir_list, tok_list))
				return (0);
		tok_list = tok_list->next;
	}
	return (1);
}

int	add_redir_in_list(t_redir **redir_list, t_token *tok_list)
{
	t_redir	*redir;
	t_redir	*tmp;

	redir = NULL;
	redir = create_redir(tok_list);
	if (!redir)
		return (0);
	tmp = NULL;
	if (!*redir_list)
		*redir_list = redir;
	else
	{
		tmp = *redir_list;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = redir;
	}
	return (1);
}

t_redir	*create_redir(t_token *tok_list)
{
	t_redir	*redir;

	redir = ft_calloc(sizeof(t_redir), 1);
	if (!redir)
		return (NULL);
	redir->name = ft_strduplicate(tok_list->word);
	if (!redir->name)
		return (free_redir(redir), NULL);
	redir->type = tok_list->type_tok;
	redir->fd = -1;
	redir->next = NULL;
	return (redir);
}
