/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/05 17:10:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parsing(char *input, t_data *data)
{
	t_input	*new_input; // Apres (new_input -> input) et (input -> raw_input)
	t_token	*tok_list;
	t_cmd	*cmd_list;

	new_input = init_input(200);
	tok_list = NULL;
	cmd_list = NULL;
	if (!expend_input(input, &new_input)) // expend_input -> malloc input
		return (0); // Free input
	free_input(&new_input); // Pour l'instant
	if (!build_list_token(input, &tok_list))
		return (0); // Free input
	if (!build_list_cmd(&cmd_list, &tok_list))
		return (0); // Free input
	free_list_token(&tok_list);
	data->cmd = &cmd_list;

	// t_cmd	*tmp_c;
	// tmp_c = *data->cmd;
	// int y = 0;
	// if (!tmp_c)
	// 	printf("no cmd\n");
	// while (tmp_c)
	// {
	// 	printf("________________CMD[%i]________________\n\n", y);
	// 	if (tmp_c->args)
	// 	{
	// 		printf("______args______\n");
	// 		int i = 0;
	// 		while (tmp_c->args[i])
	// 		{
	// 			printf("arg[%d] : '%s'\n", i, tmp_c->args[i] ? tmp_c->args[i] : "(null)");
	// 			i++;
	// 		}
	// 	}
	// 	else
	// 		printf("args = NULL\n");
	// 	printf("\n");
	// 	t_redir	*tmp_r;
	// 	tmp_r = tmp_c->redirs;
	// 	if (tmp_r)
	// 	{
	// 		printf("______redir______\n");
	// 		int i = 0;
	// 		while (tmp_r)
	// 		{
	// 			printf("file[%i]   ", i);
	// 			printf("name = '%s'   ", tmp_r->name ? tmp_r->name : "(null)");
	// 			printf("type = '%s'", type_to_str(tmp_r->type));
	// 			printf("\n");
	// 			tmp_r = tmp_r->next;
	// 			i++;
	// 		}
	// 	}
	// 	else
	// 		printf("redir = NULL\n");
	// 	printf("\n");
	// 	tmp_c = tmp_c->next;
	// 	y++;
	// }
	// free_list_cmd(&cmd_list);
	// return(1);

	exec_pipex(data, data->cmd);
	return (1);
}

t_input *init_input(int size)
{
	t_input *input;

	input = ft_calloc(sizeof(t_input), 1);
	if (!input)
		return (NULL);
	input->str = ft_calloc(size + 1, sizeof(char));
	if (!input->str)
		return (free(input), NULL);
	input->str[0] = '\0';
	input->in_squote = 0;
	input->in_dquote = 0;
	input->size = size;
	input->len = 0;
	return (input);
}

