/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:27:39 by rerichar          #+#    #+#             */
/*   Updated: 2025/04/26 21:39:35 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*ptr;
	char	*ptr2;

	if (dest == NULL && src == NULL)
		return (NULL);
	ptr = (char *) src;
	ptr2 = (char *) dest;
	i = 0;
	while (n--)
	{
		ptr2[i] = ptr[i];
		i++;
	}
	return (ptr2);
}

/*
#include<stdio.h>

int main(void)
{
    char dest[10] = "boujour";
    ft_memcpy(dest, "bousoir", 7);
    printf("%s\n", dest);
    return 0;
}
*/
