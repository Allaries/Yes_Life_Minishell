/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_list_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:32:15 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/17 18:52:10 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// Ici il faut verifier si il y a bien un argumemt dans chaque commandes et aussi apres le pipe

int	verify_list_token(t_token **tok_list)
{
	t_token		*tok;

	if (!tok_list || !*tok_list)
		return (0);
	tok = *tok_list;
	if (!is_good_pipe(tok))
		return (0);
	if (!is_there_file(tok))
		return (0);
	return (1);
}

int	is_good_pipe(t_token *tok)
{
	if ((tok->type_tok) == PIPE)
	{
		printf("Syntax error: the command starts with a pipe\n");
		return (0);
	}
	while (tok->next)
	{
		if (tok->type_tok == PIPE && tok->next->type_tok == PIPE)
		{
			printf("Syntax error: consecutive pipes\n");
			return (0);
		}
		tok = tok->next;
	}
	if ((tok->type_tok) == PIPE)
	{
		printf("Syntax error: the command ends with a pipe\n");
		return (0);
	}
	return (1);
}

int	is_there_file(t_token *tok)
{
	while (tok)
	{
		if ((tok->type_tok) == REDIR_IN
			|| (tok->type_tok) == REDIR_OUT
			|| (tok->type_tok) == HEREDOC
			|| (tok->type_tok) == APPEND)
		{
			if (!tok->next || tok->next->type_tok != ARG)
			{
				printf("Syntax error: expected a file but none was given\n");
				return (0);
			}
		}
		tok = tok->next;
	}
	return (1);
}
