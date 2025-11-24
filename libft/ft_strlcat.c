/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 01:14:18 by rerichar          #+#    #+#             */
/*   Updated: 2025/05/07 13:51:49 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = dest_len;
	j = 0;
	if (n == 0)
		return (src_len);
	if (n < dest_len)
		return (src_len + n);
	else
	{
		while (src[j] && (dest_len + j) < n - 1)
		{
			dest[i] = src[j];
			i++;
			j++;
		}
		if (i < n)
			dest[i] = '\0';
		return (dest_len + src_len);
	}
}
/*
int main(void)
{
	int i;
    	char dest[15] = "j'aimel't";
    	i = ft_strlcat(dest, "o", 13);
    	printf("%s\n%i\n", dest, i);
    	return (0);
}*/
