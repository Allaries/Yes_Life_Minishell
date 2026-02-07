/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/30 17:30:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

// int	is_tok(char *input, int start, int len)
// {
// 	if (!len)
// 		return (0);
// 	if ((len == 1) && (input[start + len - 1] == '>'))
// 		if (input[start + len] == '>')
// 			return (0);
// 	if ((len == 1) && (input[start + len - 1] == '<'))
// 		if (input[start + len] == '<')
// 			return (0);
// 	if ((input[start + len - 1] == '>') || (input[start + len - 1] == '<')
// 		|| (input[start + len - 1] == '|'))
// 		return (1);
// 	if ((input[start + len] == '>') || (input[start + len] == '<')
// 		|| (input[start + len] == '|'))
// 		return (1);
// 	return (0);
// }

enum e_tok	which_type(char *buf)
{
	if (!buf[0])
		return (VOID);
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
	return (ARG);
}
