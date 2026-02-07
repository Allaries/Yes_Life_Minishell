/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/07 05:28:30 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	build_list_token(char *input, t_token **tok_list)
{
	if (!input || !*input)
		return (0);
	if (!expend_input(input)) // expend_input -> malloc new input
		return (0);
	if (!check_quote(input))
		return (0);
	if (!fill_list_token(input, tok_list))
		return (0);
	if (!verify_list_token(tok_list))
		return (0);
	if (!modify_list_token(tok_list))
		return (0);
	return (1);
}
