/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:51:07 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/16 06:41:46 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	expend_input(char *input, t_input **new_input)
{
	int	i;

	i = 0;
	if (!input || !*input)
		return (0);
	if (!new_input || !*new_input)
		return (0);
	while(input[i])
	{
		i++;
	}
	return (1);
}

// int	add_char_in_input(t_input *new_input, char c)
// {
// 	if (new_input->len + 1 >= new_input->size)
// 		if (!realloc_word(new_input))
// 			return (0);
// 	new_input->str[new_input->len] = c;
// 	(new_input->len)++;
// 	new_input->str[new_input->len] = '\0';
// 	return (1);
// }

// int	realloc_input(t_input *new_input)
// {
// 	char	*tmp_str;

// 	tmp_str = NULL;
// 	word->size = word->size + word->size;
// 	tmp_buf = ft_realloc(word->buf, word->size);
// 	if (!tmp_buf)
// 		return (0);
// 	word->buf = tmp_buf;
// 	return (1);
// }
