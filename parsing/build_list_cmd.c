/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:46:22 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/05 20:46:22 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	build_list_cmd(t_cmd **cmd_list, t_token **tok_list)
{
	if (!fill_list_cmd(cmd_list, tok_list))
		return (0);
	return (1);
}

int	fill_list_cmd(t_cmd	**cmd_list, t_token **tok_list)
{
	int	i;
	t_token	*tmp;

	i = 0;
	tmp = *tok_list;
	while (tmp)
	{
		if (!add_cmd_in_list(cmd_list, tmp))
		{
			printf ("a ce soir la team\n");
			return (0);
		}
		while (tmp && tmp->type_tok != PIPE)
			tmp = tmp->next;
		if (tmp)
			tmp = tmp->next;
	}
	return (1);
}

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
	t_redir	**redir_list;
	char	**args;

	redir_list = NULL;
	args = NULL;
	cmd = ft_calloc(sizeof(t_cmd), 1);
	if (!cmd)
		return (NULL);
	cmd->args = build_args(tok_list);
	if (!cmd->args)
		return (NULL); // + Free la cmd
	if (!build_redir_list(redir_list, tok_list))
		return (0); // + Free la cmd + Free args
	cmd->redirs = redir_list;
	cmd->path = NULL;
	cmd->infd = 0;
	cmd->outfd = 1;
	cmd->pid = 0;
	cmd->built_in = 0;
	cmd->next = NULL;
	return (cmd);
}

char	**build_args(t_token *tok_list)
{
	int		len;
	t_token	*tmp;
	char	**args;

	len = 0;
	tmp = tok_list;
	while (tmp && tmp->type_tok != PIPE)
	{
		if (tmp->type_tok == ARG)
			len++;
		tmp = tmp->next;
	}
	if (!len) // au cas ou
		return (NULL);
	args = ft_calloc(sizeof(char *) * (len + 1), 1);
	if (!args)
		return (NULL);
	len = 0;
	while (tok_list && tok_list->type_tok != PIPE)
	{
		if (tok_list->type_tok == ARG)
		{
			args[len] = ft_strduplicate(tok_list->word);
			if (!args[len])
				return (NULL); // free all args
			len++;
		}
		tok_list = tok_list->next;
	}
	return (args);
}

int	build_redir_list(t_redir **redir_list, t_token *tok_list)
{
	while (tok_list && tok_list->type_tok != PIPE)
	{
		printf("type tok = %i\n", tok_list->type_tok);
		if (tok_list->type_tok == INFILE || tok_list->type_tok == OUTFILE
			|| tok_list->type_tok == HEREDOC_F || tok_list->type_tok == APPEND_F)
		{
			if (!add_redir_in_list(redir_list, tok_list))
				return (0);
		}
		tok_list = tok_list->next;
	}
	return (1);
}

int	add_redir_in_list(t_redir **redir_list, t_token *tok_list)
{
	t_redir	*redir;
	t_redir	*tmp;

	redir = create_redir(tok_list);
	if (!redir)
		return (0);
	tmp = NULL;
	if (!*redir_list)
		*redir_list = redir;
	else
	{
		tmp = *redir_list;
		while (tmp->next)
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
		return (NULL); // + Free la redir
	redir->type = tok_list->type_tok;
	redir->fd = -1;
	redir->next = NULL;
	return (redir);
}
