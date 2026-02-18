/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:51:07 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/18 04:44:07 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	which_quote_inp(t_input *new_input)
{
	if (new_input->in_dquote)
		return (2);
	if (new_input->in_squote)
		return (1);
	return (0);
}

int	add_char_in_input(t_input *new_input, char c)
{
	if (new_input->len + 1 >= new_input->size)
		if (!realloc_input(new_input))
			return (0);
	new_input->str[new_input->len] = c;
	(new_input->len)++;
	new_input->str[new_input->len] = '\0';
	return (1);
}

int	realloc_input(t_input *new_input)
{
	char	*tmp_str;

	tmp_str = NULL;
	new_input->size = new_input->size + new_input->size;
	tmp_str = ft_realloc(new_input->str, new_input->size);
	if (!tmp_str)
		return (0);
	new_input->str = tmp_str;
	return (1);
}

void	toggle_quote_inp(char *input, t_input *new_input, int *i)
{
	if (input[*i] == '\'')
		new_input->in_squote = !new_input->in_squote;
	else if (input[*i] == '"')
		new_input->in_dquote = !new_input->in_dquote;
	//(*i)++; Pas besoin
}
