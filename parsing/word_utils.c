/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:19:56 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/29 14:51:48 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	add_char_in_word(t_word *word, char char_buf, char char_mask)
{
	if (word->len + 1 >= word->size)
		if (!realloc_word(word))
			return (0);
	word->buf[word->len] = char_buf;
	word->qmask[word->len] = char_mask;
	word->len++;
	word->buf[word->len] = '\0';
	word->qmask[word->len] = '\0';
	return (1);
}

int	realloc_word(t_word *word)
{
	char	*tmp_buf;
	char	*tmp_qmask;

	tmp_buf = NULL;
	tmp_qmask = NULL;
	word->size = word->size + word->size;
	tmp_buf = realloc(word->buf, word->size);
	if (!tmp_buf)
		return (0);
	word->buf = tmp_buf;
	tmp_qmask = realloc(word->qmask, word->size);
	if (!tmp_qmask)
		return (0);
	word->qmask = tmp_qmask;
	return (1);
}

