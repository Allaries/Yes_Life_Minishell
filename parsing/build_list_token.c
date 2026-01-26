/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/26 14:43:47 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	build_list_token(t_token **tok_list, char *input)
{
	if (!iterate_input(tok_list, input))
		return (0);
	return (1);
}

int	iterate_input(t_token **tok_list, char *input)
{
	int	i;

	i = 0;
	if (!input || !input[0])
		return (1);
	while (input[i])
	{
		if (!is_space(input[i]))
		{
			if (!create_word(tok_list, input, &i))
				return (0);
		}
		else
			i++;
	}
	return (1);
}
