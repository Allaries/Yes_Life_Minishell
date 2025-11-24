/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:00:22 by rerichar          #+#    #+#             */
/*   Updated: 2025/04/25 18:24:50 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && (i + j) < len)
			{
				j++;
				if (j == ft_strlen(little))
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (0);
}

/* #include<stdio.h>

int	main(void)
{
	char	*pong;

	pong = "AAAAAABA";
	printf("%s",ft_strnstr(pong, "", 8));
}*/
