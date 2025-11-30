/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:46 by smedenec          #+#    #+#             */
/*   Updated: 2025/11/30 19:07:23 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	int		i;
	char	*str_stdint;
	t_list	*list;

	i = 0;
	while (i++ <= 4)
	{
		str_stdint = readline(NULL);
		if (!str_stdint)
		{
			perror("Error");
			return (1);
		}
		list = create_list(str_stdint);
		if (!list)
		{
			printf("Error, list NULL\n");
			return (1);
		}
		// send list to exec
		free(str_stdint);
	}
	return (0);
}
