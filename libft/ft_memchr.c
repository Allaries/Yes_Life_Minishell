/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:01:46 by rerichar          #+#    #+#             */
/*   Updated: 2025/04/23 18:16:49 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return (&ptr[i]);
		i++;
	}
	return (0);
}

// #include<stdio.h>
// #include<string.h>
// int     main(void)
// {
//         char ptr[] = "sa\258";
//         printf("|%s|", (char *)ft_memchr(ptr, 2 + 256, 3));
// 		printf("|%s|", (char *)memchr(ptr, 2 + 256, 3));
// 		// printf("|%s|", (char *)memchr());
// }
