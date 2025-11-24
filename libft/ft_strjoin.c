/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:13:31 by rerichar          #+#    #+#             */
/*   Updated: 2025/04/25 15:36:32 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		totlen;
	int		i;
	int		j;

	totlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = malloc(sizeof (*ptr) * totlen);
	if (ptr == NULL)
		return (0);
	j = 0;
	i = 0;
	while (s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	return (ptr);
}
/*
#include<stdio.h>
int	main(void)
{
	printf("%s",ft_strjoin("hello","world"));
	return (0);
}*/
