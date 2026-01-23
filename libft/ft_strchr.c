/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:23:40 by rerichar          #+#    #+#             */
/*   Updated: 2025/04/23 18:17:14 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

// #include <bsd/string.h>
// #include <stdio.h>
// int     main(void)
// {
// 		printf("%s\n", ft_strchr("teste", '\0'));
//         printf("%s\n",strchr("teste", '\0'));
// }
