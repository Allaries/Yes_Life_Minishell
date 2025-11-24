/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:34:04 by rerichar          #+#    #+#             */
/*   Updated: 2025/04/26 21:37:51 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*ptr;
	char	*ptr2;

	if (!dest && !src)
		return (NULL);
	ptr = (char *) src;
	ptr2 = (char *) dest;
	if (dest > src && dest < src + n)
	{
		while (n--)
			ptr2[n] = ptr[n];
	}
	else
	{
		i = 0;
		while (n--)
		{
			ptr2[i] = ptr[i];
			i++;
		}
	}
	return (ptr2);
}

/*
#include<stdio.h>

int main(void)
{
    char dest[10] = "boujour";
    ft_memmove(dest, "delete", 6);
    printf("%s\n", dest);
    return 0;
}*/
