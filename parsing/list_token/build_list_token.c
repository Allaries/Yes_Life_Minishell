/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/17 18:41:13 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	build_list_token(char *input, t_data *data, t_token **tok_list)
{
	if (!input || !*input)
		return (0);
	if (!check_quote(input))
	{
		printf("Syntax error: a quote was opened but not closed\n");
		return (0);
	}
	if (!fill_list_token(input, data, tok_list))
	{
		printf("Memory error: token list allocation failed\n");
		return (0);
	}
	// printf("\n--- DEBUG TOKEN LIST ---\n");
	// t_token *tmp = *tok_list;
	// int idx = 0;
	// while (tmp)
	// {
	// 	printf("[%d] token @ %p\n", idx, (void *)tmp);
	// 	// type_tok
	// 	printf("   type_tok : %s\n", type_to_str(tmp->type_tok));
	// 	// word (NULL-safe)
	// 	if (tmp->word)
	// 		printf("   word     : '%s'\n", tmp->word);
	// 	else
	// 		printf("   word     : (null)\n");
	// 	// next pointer
	// 	printf("   next     : %p\n\n", (void *)tmp->next);
	// 	tmp = tmp->next;
	// 	idx++;
	// }
	// printf("--- END TOKEN LIST ---\n\n");
	if (!verify_list_token(tok_list))
	{
		free_list_token(tok_list);
		return (0);
	}
	define_file_token(tok_list);
	return (1);
}
