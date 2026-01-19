/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:41:21 by rerichar          #+#    #+#             */
/*   Updated: 2026/01/19 12:12:18 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	free_file(t_file **filelist)
// {
// 	t_file	*temp;
// 	t_file	*temp_next;

// 	temp = *filelist;
// 	while (temp->next != NULL)
// 	{
// 		temp_next = temp->next;
// 		if (temp->name)
// 			free (temp->name);
// 		temp->next = NULL;
// 		free (temp);
// 		temp = temp_next;
// 	}
// 	return ;
// }

// void	free_cmd_struct(t_cmd **cmd)
// {
// 	t_cmd	*temp;
// 	t_cmd	*temp_next;

// 	temp = *cmd;
// 	while(temp->next != NULL)
// 	{
// 		temp_next = temp->next;
// 		free_tab(temp->next);
// 		free_file(temp->filelist);
// 		temp->next = NULL;
// 		free (temp);
// 		temp = temp_next;
// 	}
// 	free_tab(temp->next);
// 	free_file(temp->filelist);
// 	temp->next = NULL;
// 	free (temp);
// 	return ;
// }
