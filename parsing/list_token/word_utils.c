/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:19:56 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/14 02:50:58 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	which_quote(t_word *word)
{
	if (word->in_dquote)
		return (2);
	if (word->in_squote)
		return (1);
	return (0);
}

int	realloc_word(t_word *word)
{
	char	*tmp_buf;

	tmp_buf = NULL;
	word->size = word->size + word->size;
	tmp_buf = ft_realloc(word->buf, word->size);
	if (!tmp_buf)
		return (0);
	word->buf = tmp_buf;
	return (1);
}

int	char_is_a_quote(char *input, int i)
{
	if (input[i] && (input[i] == '\'') || (input[i] == '"'))
		return (1);
	return (0);
}

void	toggle_quote(char *input, t_word *word, int *i)
{
	if (input[*i] == '\'')
		word->in_squote = !word->in_squote;
	else if (input[*i] == '"')
		word->in_dquote = !word->in_dquote;
	printf("sq = %d dq = %d\n", word->in_squote, word->in_dquote);
	(*i)++;
}
