/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/20 19:45:45 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_quote(char *input)
{
	if (!input || !*input)
		return (0);
	if (!is_pair(input))
		return (0);
	return (1);
}

int	is_pair(char *input)
{
	int		i;
	int		pair;

	i = 0;
	pair = 1;
	while (input[i])
	{
		if (input[i] == '\'')
			pair = find_second_quote(input, '\'', &i);
		else if (input[i] == '"')
			pair = find_second_quote(input, '"', &i);
		else
			i++;
	}
	return (pair);
}

int	find_second_quote(char *input, char q, int *i)
{
	int find;

	find = 0;
	(*i)++;
	while (input[*i])
	{
		if (input[*i] == q)
		{
			find = 1;
			(*i)++;
			break;
		}
		(*i)++;
	}
	return (find);
}
