/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:51:07 by rerichar          #+#    #+#             */
/*   Updated: 2025/04/23 18:14:49 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
#include<stdio.h>
int	main(void)
{
	char	*str1;
	char	*str2;
	str1 = "boujour";
	str2 = "boujour";

	if (ft_memcmp(str1, str2, 8) > 0)
		printf("+");
	else if (ft_memcmp(str1, str2, 8) < 0)
		printf("-");
	else printf("0");
}
*/
