/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:38:06 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/23 23:15:55 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptitecoquille/minishell.h"

t_file	*lstnew_file_heredoc(char *name)
{
	t_file	*new;

	new = malloc(sizeof(t_file));
	if (!new)
		return (NULL);
	new->name = name;
	new->type = HEREDOC_F;
	new->next = NULL;
	return (new);
}

t_file	*lstnew_file_outfile(char *name)
{
	t_file	*new;

	new = malloc(sizeof(t_file));
	if (!new)
		return (NULL);
	new->name = name;
	new->type = OUTFILE;
	new->next = NULL;
	return (new);
}

t_file	*lstnew_file_infile(char *name)
{
	t_file	*new;

	new = malloc(sizeof(t_file));
	if (!new)
		return (NULL);
	new->name = name;
	new->type = INFILE;
	new->next = NULL;
	return (new);
}
t_file	*lstnew_file_append(char *name)
{
	t_file	*new;

	new = malloc(sizeof(t_file));
	if (!new)
		return (NULL);
	new->name = name;
	new->type = APPEND_F;
	new->next = NULL;
	return (new);
}

void	lstadd_back_file(t_file **lst, t_file *new)
{
	t_file	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_cmd	*lstnew_cmd_filelist(char **args)
{
	t_cmd	*new;
	t_file	**filelist;
	t_file	*node;

	filelist = calloc(1, sizeof(t_file *));
	node = lstnew_file_infile("main.c");
	lstadd_back_file(filelist, node);
	node = lstnew_file_infile("Makefile");
	lstadd_back_file(filelist, node);
	node = lstnew_file_append("Youplaboum");
	lstadd_back_file(filelist, node);
	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->filelist = filelist;
	new->args = args;
	new->next = NULL;
	return (new);
}

t_cmd	*lstnew_cmd(char **args)
{
	t_cmd	*new;
	t_file	**filelist;
	t_file	*node;

	filelist = NULL;
	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->filelist = filelist;
	new->args = args;
	new->next = NULL;
	return (new);
}

void	lstadd_back_cmd(t_cmd **lst, t_cmd *new)
{
	t_cmd	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int main(int argc, char **argv, char **envp)
{
	t_data	data;
	t_cmd	**cmds;
	t_cmd	*node;
	char	**args1;
	char	**args2;

	if (argc < 3)
	{
		printf("usage: %s cmd1 cmd2\n", argv[0]);
		return (1);
	}
	data.pid = calloc(sizeof(int), 2);
	/* allocation du tableau de commandes */
	cmds = calloc(1, sizeof(t_cmd *));
	if (!cmds)
		return (1);

	/* première commande */
	args1 = calloc(2, sizeof(char *));
	args1[0] = argv[1];
	args1[1] = NULL;
	node = lstnew_cmd_filelist(args1);
	lstadd_back_cmd(cmds, node);

	/* deuxième commande */
	args2 = calloc(2, sizeof(char *));
	args2[0] = argv[2];
	args2[1] = NULL;
	node = lstnew_cmd(args2);
	lstadd_back_cmd(cmds, node);

	/* environnement */
	data.envp = dupe_env(envp);

	/* exécution */
	exec_pipex(&data, cmds);

	return (0);
}