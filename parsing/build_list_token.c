/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/29 18:48:15 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	build_list_token(char *input, t_token **tok_list)
{
	if (!check_input(input))
		return (0);
	if (!check_quote(input))
		return (0);
	if (!fill_token_list(input, tok_list))
		return (0);
	if (!verify_list_token(tok_list))
		return (0);
	return (1);
}

int	fill_token_list(char *input, t_token **tok_list)
{
	int		i;
	t_word	*word;

	i = 0;
	word = NULL;
	while (input[i])
	{
		if (is_space(input[i]))
			i++;
		else
		{
			word = init_word(32);
			if (!word)
				return (free_all(tok_list, NULL), 0);
			if (!parse_word(input, &word, &i))
			{
				printf("et la c'est le drame\n");
				return (free_all(tok_list, &word), 0);

			}

			if (!add_tok_in_list(tok_list, &word))
				return ((free_all(tok_list, &word), 0));
			free_all(NULL, &word);
		}
	}
	return (1);
}
