/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:03:22 by rerichar          #+#    #+#             */
/*   Updated: 2025/04/28 18:40:17 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

int	intlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	i = intlen(n);
	ptr = malloc(sizeof (char) * i + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[i] = '\0';
	i--;
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	while (n > 9)
	{
		ptr[i] = (n % 10 + '0');
		n = n / 10;
		i--;
	}
	ptr[i] = n + '0';
	return (ptr);
}

// int	main(void)
// {
// 		printf("%s", ft_itoa((-2147483648)));
// }