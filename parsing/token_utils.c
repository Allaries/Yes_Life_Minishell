/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/29 20:42:03 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_tok(char *input, int i, int len)
{
	if (!len) // Ici ameliorer en ajoutant char c = input[c]
		return (0);
	if (len == 1)
	{
		if ((input[i - 1] == '>') && (input[i] == '>'))
			return (0);
		if ((input[i - 1] == '<') && (input[i] == '<'))
			return (0);
	}
	if ((input[i - 1] == '>') || (input[i - 1] == '<') || (input[i - 1] == '|'))
		return (1);
	if ((input[i] == '>') || (input[i] == '<') || (input[i] == '|'))
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
	if (!ft_strcmp_safe(buf, "<"))
		return (REDIR_IN);
	if (!ft_strcmp_safe(buf, ">"))
		return (REDIR_OUT);
	if (!ft_strcmp_safe(buf, "<<"))
		return (HEREDOC);
	if (!ft_strcmp_safe(buf, ">>"))
		return (APPEND);
	if (!ft_strcmp_safe(buf, "|"))
		return (PIPE);
	return (ARG);
}
