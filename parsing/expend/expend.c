/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:51:07 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/18 04:54:33 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	expend_input(char *input, t_input **new_input)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	if (!new_input || !*new_input) // a enlever sert a rien
		return (0);
	while(input[i] && is_quote(input, *new_input, &i) && is_expend(input, *new_input, &i))
	{

		c = input[i];
		if (!add_char_in_input(*new_input, c))
			return (0);
		i++;
	}
	return (1);
}

int	is_quote(char *input, t_input *new_input, int *i)
{
	int		q;
	char	c;

	q = 0;
	c = 0;
	if (char_is_a_quote(input, *i))
	{
		q = which_quote_inp(new_input);
		c = input[*i];
		if (!q)
			toggle_quote_inp(input, new_input, i);
		else if ((q == 1 && input[*i] == '\'') || (q == 2 && input[*i] == '"'))
			toggle_quote_inp(input, new_input, i);
		else
			return (1);
	}
	if (!input[*i])
		return (0);
	return (1);
}

int	is_expend(char *input, t_input *new_input, int *i)
{
	if (input[*i] == '$')
	{
		if (new_input->in_squote)
			return (1);
		else
			go_expend(input, new_input, i);
		(*i)++;
	}
	if (input[*i] == '$')
		is_expend(input, new_input, i);
	if (!input[*i])
		return (0);
	return (1);
}

void	go_expend(char *input, t_input *new_input, int *i)
{
	if (!input)
		return ;
	if (!new_input) // a enlever sert a rien
		return ;
	// strduplicate le mot (while !is_space)
	// trouver la variable d'env
	// strduplicate la varaible d'env
	// et add_char_in_word la variable d'env
}
