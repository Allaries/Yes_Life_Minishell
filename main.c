/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:46 by smedenec          #+#    #+#             */
/*   Updated: 2025/12/14 03:57:09 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*error_free_all(t_list **node)
{
	int	i;

	i = 0;
	return (NULL);
}

void	one_arg(str_stdint)
{
	if (!str_stdint)
		return ;
	while ((str_stdint[i] >= 8 && str_stdint[i] <= 13) || str_stdint[i] == 32)
		i++;
	if (str_stdint[i] == '"')
}
void	parsing(char *str_stdint)
{
	int	i;

	i = 0;


}

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
		parsing(str_stdint);
		// list = create_list(str_stdint);
		// if (!list)
		// {
		// 	printf("Error, list NULL\n");
		// 	return (1);
		// }
		// send list to exec
		// if (list)
		// 	free_list(&list);
		free(str_stdint);
	}
	return (0);
}

// void	*free_list(t_list **node)
// {
// 	int	i;
// 	int	y;
// 	t_list	next_node;

// 	i = 0;
// 	y = 0;
// 	if (!node)
// 		return (NULL);
// 	while (len--)
// 	{
// 		if (node[len] && node[len]->cmd)
// 		{

// 		}
// 	}
// 	return (NULL);
// }

// int	len_node(t_list **node)
// {
// 	int	len;

// 	len = 0;
// 	while (node && (node[len] != NULL))
// 		len++;
// 	return (len);
// }


