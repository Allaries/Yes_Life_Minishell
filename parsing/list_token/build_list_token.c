/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/13 00:45:04 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	build_list_token(char *input, t_token **tok_list)
{
	if (!input || !*input)
		return (0);
	if (!check_quote(input))
		return (0);
	if (!fill_list_token(input, tok_list))
	{
		printf("fill_list_token, Non\n");
		return (0);
	}
	if (!verify_list_token(tok_list))
	{
		printf("verify_list_token, Non\n");
		return (0);
	}
	if (!define_file_token(tok_list))
	{
		printf("define_file_token, Non\n");
		return (0);
	}
	return (1);
}
