/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:14:42 by rerichar          #+#    #+#             */
/*   Updated: 2025/05/06 19:54:25 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_trim(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	trimstart(const char *str, const char *set)
{
	int	i;

	i = 0;
	while (str[i] && is_trim(str[i], set))
		i++;
	return (i);
}

int	trimend(const char *str, const char *set)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && is_trim(str[i], set))
		i--;
	return (i);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		j;
	char	*ptr;

	if (s1 == NULL)
		return (NULL);
	i = trimstart(s1, set);
	j = trimend(s1, set);
	if (j < i)
		return (ft_strdup(""));
	ptr = ft_substr(s1, i, (j - i + 1));
	return (ptr);
}

// #include<stdio.h>
// int		main(void)
// {
// 	printf("|%s|", ft_strtrim("hello", "ho"));
// }
