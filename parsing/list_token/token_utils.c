/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/14 02:09:46 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_tok(char *input, int i, int len)
{
	char	c;
	char	c_prev;

	c = '\0';
	c_prev = '\0';
	if (!len)
		return (0);
	c = input[i];
	c_prev = input[i - 1];
	if (len == 1)
	{
		if ((c_prev == '>') && (c == '>'))
			return (0);
		if ((c_prev == '<') && (c == '<'))
			return (0);
	}
	if ((c_prev == '>') || (c_prev == '<') || (c_prev == '|'))
		return (1);
	if ((c == '>') || (c == '<') || (c == '|'))
		return (1);
	return (0);
}

enum e_tok	which_type(char *buf, int was_quote)
{
	if (!was_quote)
	{
		if (!ft_strcmp_safe(buf, "|"))
			return (PIPE);
		if (!ft_strcmp_safe(buf, "<"))
			return (REDIR_IN);
		if (!ft_strcmp_safe(buf, ">"))
			return (REDIR_OUT);
		if (!ft_strcmp_safe(buf, "<<"))
			return (HEREDOC);
		if (!ft_strcmp_safe(buf, ">>"))
			return (APPEND);
	}
	return (ARG);
}
