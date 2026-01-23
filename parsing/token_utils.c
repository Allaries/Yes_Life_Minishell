/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/23 14:33:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_tok(char *input, int start, int len)
{
	if (!len)
		return (0);
	if ((len == 1) && (input[start + len - 1] == '>'))
		if (input[start + len] == '>')
			return (0);
	if ((len == 1) && (input[start + len - 1] == '<'))
		if (input[start + len] == '<')
			return (0);
	if ((input[start + len - 1] == '>') || (input[start + len - 1] == '<')
		|| (input[start + len - 1] == '|'))
		return (1);
	if ((input[start + len] == '>') || (input[start + len] == '<')
		|| (input[start + len] == '|'))
		return (1);
	return (0);
}

enum e_type_tok	which_type(char *word)
{
	if (!word)
		return (CQUOI);
	if (!ft_strcmp_safe(word, "<"))
		return (REDIR_IN);
	if (!ft_strcmp_safe(word, ">"))
		return (REDIR_OUT);
	if (!ft_strcmp_safe(word, "<<"))
		return (HEREDOC);
	if (!ft_strcmp_safe(word, ">>"))
		return (APPEND);
	if (!ft_strcmp_safe(word, "|"))
		return (PIPE);
	return (ARG);
}
