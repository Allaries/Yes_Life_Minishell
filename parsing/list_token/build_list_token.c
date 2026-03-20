/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/03/20 18:50:37 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	build_list_token(char *input, t_data *data, t_token **tok_list)
{
	if (!input || !*input)
		return (0);
	if (!check_quote(input))
	{
		printf("Syntax error: a quote was opened but not closed\n");
		data->exit_code = 2;
		return (0);
	}
	if (!fill_list_token(input, data, tok_list))
	{
		printf("Memory error: token list allocation failed\n");
		data->exit_code = 1;
		return (0);
	}
	if (!verify_list_token(tok_list))
	{
		free_list_token(tok_list);
		data->exit_code = 2;
		return (0);
	}
	define_file_token(tok_list);
	return (1);
}
