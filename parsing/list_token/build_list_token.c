/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/18 04:01:22 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	build_list_token(char *input, t_token **tok_list)
{
	if (!input || !*input)
		return (0);
	if (!check_quote(input))
		return (0);
	if (!fill_list_token(input, tok_list))
	{
		printf("fill_list_token, Non\n");
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


	//yo ma soeur c'est le R
	//ca leakais ici pasque ca free pas si les check sont mauvais
	//(c'est pour ca que la commande a Yanis leakais)
	//+ faudrais rajouter un check pour quand t'as des double/quotes pas fermees
	//+ des messages d'erreurs plus explicites que "verify_list_token, Non"
	if (!verify_list_token(tok_list))
	{
		free_list_token(tok_list);
		printf("verify_list_token, Non\n");
		return (0);
	}
	if (!define_file_token(tok_list))
	{
		free_list_token(tok_list);
		printf("define_file_token, Non\n");
		return (0);
	}
	return (1);
}
