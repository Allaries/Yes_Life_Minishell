/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:46 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/05 17:12:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(void)
{
	int		i;
	char	*input;

	i = 0;
	while (++i <= 1)
	{
		input = readline(NULL);
		if (!input)
		{
			perror("Error");
			return (1);
		}
		parsing(input);
		free(input);
		input = NULL;
	}
	return (0);
}

// to compile : valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ./minishell
