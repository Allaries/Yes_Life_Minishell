/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:46 by smedenec          #+#    #+#             */
/*   Updated: 2026/01/27 18:42:12 by smedenec         ###   ########.fr       */
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
		build_cmd(input);
		free(input);
		input = NULL;
	}
	return (0);
}
