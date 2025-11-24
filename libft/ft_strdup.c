/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:46:44 by rerichar          #+#    #+#             */
/*   Updated: 2025/04/24 19:25:48 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	ptr = malloc(sizeof (*ptr) * (ft_strlen((char *)s) + 1));
	if (ptr == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
#include<stdio.h>
int	main(void)
{
	printf("%s",ft_strdup("skill issue ?"));
}*/
