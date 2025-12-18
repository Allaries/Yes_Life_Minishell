/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:46 by smedenec          #+#    #+#             */
/*   Updated: 2025/12/18 08:22:32 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	separate_word(char *input)
{
	char	**str_split;
	int	i;

	i = -1;
	str_split = NULL;
	str_split = ft_split(input, '|');
	if (!str_split)
		return ;
	str_split = remove_space(str_split);
	while (str_split[++i])
		printf("%s\n", str_split[i]);
}

void	parsing(char *input)
{
	divise_word(input);
}

int	main(void)
{
	int		i;
	char	*input;
	t_node	*list;

	i = 0;
	while (i++ <= 4)
	{
		input = readline(NULL);
		if (!input)
		{
			perror("Error");
			return (1);
		}
		parsing(input);
		// list = create_list(input);
		// if (!list)
		// {
		// 	printf("Error, list NULL\n");
		// 	return (1);
		// }
		// send list to exec
		// if (list)
		// 	free_list(&list);
		free(input);
	}
	return (0);
}
