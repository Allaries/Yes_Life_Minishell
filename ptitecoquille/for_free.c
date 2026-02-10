/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 22:36:20 by rerichar          #+#    #+#             */
/*   Updated: 2026/02/10 14:26:58 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}

void	free_file(t_redir *filelist)
{
	t_redir	*temp;
	t_redir	*temp_next;
	
	if (filelist == NULL)
		return ;
	temp = filelist;
	while (temp)
	{
		temp_next = temp->next;
		if (temp->name)
			free(temp->name);
		temp->next = NULL;
		if (temp)
			free(temp);
		temp = temp_next;
	}
	return ;
}

void	free_cmd_struct(t_cmd **cmd)
{
	t_cmd	*temp;
	t_cmd	*temp_next;

	if (cmd == NULL)
		return ;
	temp = *cmd;
	while(temp)
	{
		temp_next = temp->next;
		if (temp->infd != 0 && temp->infd != -1)
			close(temp->infd);
		if (temp->outfd != 1 && temp->outfd != -1)
			close(temp->outfd);
		free_tab(temp->args);
		free_file(temp->redirs);
		if (temp->path)
			free(temp->path);
		temp->next = NULL;
		free (temp);
		temp = temp_next;
	}
	if (temp)
		free (temp);
	return ;
}

void	thanos_snap_process(t_data *data)
{
	free_tab(data->envp);
	free_cmd_struct(data->cmd);
	data->cmd = NULL;
}