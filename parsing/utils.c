/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:57:03 by smedenec          #+#    #+#             */
/*   Updated: 2026/02/06 05:35:21 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_space(char c)
{
	return ((c == ' ') || (c >= 8 && c <= 13));
}

int	ft_strcmp_safe(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (1);
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	*ft_strduplicate(const char *s)
{
	int		i;
	int		len;
	char	*str;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = ft_calloc(sizeof(char) * (len + 1), 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_realloc(void *ptr, size_t new_size)
{
	char	*new_ptr;
	char	*src;
	size_t	i;

	if (!ptr)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	src = ptr;
	i = 0;
	while (i < new_size)
	{
		new_ptr[i] = src[i];
		i++;
	}
	free(ptr);
	return (new_ptr);
}
