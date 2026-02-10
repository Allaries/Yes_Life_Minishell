/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:33:17 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/10 16:59:07 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	add_cmd_in_list(t_cmd **cmd_list, t_token *tok_list)
{
	t_cmd	*cmd;
	t_cmd	*tmp;

	cmd = create_cmd(tok_list);
	if (!cmd)
		return (0);
	tmp = NULL;
	if (!*cmd_list)
		*cmd_list = cmd;
	else
	{
		tmp = *cmd_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = cmd;
	}
	return (1);
}

t_cmd	*create_cmd(t_token *tok_list)
{
	t_cmd	*cmd;
	t_redir	*redir_list;
	char	**args;

	args = NULL;
	redir_list = NULL;
	cmd = ft_calloc(sizeof(t_cmd), 1);
	if (!cmd)
		return (NULL);
	cmd->args = fill_args(tok_list);
	if (!cmd->args)
		return (free_cmd(cmd), NULL);
	if (!fill_list_redir(&redir_list, tok_list))
		return (free_cmd(cmd), NULL);
	cmd->redirs = redir_list;
	cmd->path = NULL;
	cmd->infd = 0;
	cmd->outfd = 1;
	cmd->pid = 0;
	cmd->built_in = 0;
	cmd->next = NULL;
	return (cmd);
}
