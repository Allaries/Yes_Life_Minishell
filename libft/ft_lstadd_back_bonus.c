/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:30:33 by rerichar          #+#    #+#             */
/*   Updated: 2025/05/15 13:56:26 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

// #include <stdio.h>
// int main(void)
// {
//     t_list **head = 0;
//     t_list  *node;
//     head = malloc(1000000000);

//     node = ft_lstnew(1);
//     ft_lstadd_back(head, node);
//         node = ft_lstnew(2);
//     ft_lstadd_back(head, node);
//         node = ft_lstnew(3);
//     ft_lstadd_back(head, node);
//     t_list  *tmp = *head;
//     while (tmp)
//     {
//         printf("%d", tmp->content);
//         tmp = tmp->next;
//     }
//     return (0);
// }
