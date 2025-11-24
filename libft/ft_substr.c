/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:00:02 by rerichar          #+#    #+#             */
/*   Updated: 2025/05/02 16:10:22 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*edgecase(void)
{
	char	*ptr;

	ptr = malloc(1);
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;
	size_t	slen;

	slen = ft_strlen((char *)s);
	if ((size_t)start > slen)
		return (edgecase());
	if (slen - start < len)
		len = slen - start;
	ptr = malloc(sizeof (char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < (int) len && s[start])
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// #include<string.h>
// int	main(void)
// {
// 	printf("|%s|", ft_substr("Tripouille", 420, 42000));
// }
