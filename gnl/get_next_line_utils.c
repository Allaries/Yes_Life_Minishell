/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:16:46 by rerichar          #+#    #+#             */
/*   Updated: 2025/06/20 15:33:12 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_edgecase(char *base, char *add)
{
	int	i;

	i = 0;
	if (!add)
		return (NULL);
	if (!*add)
		return (base);
	if (!base)
	{
			base = ft_calloc(ft_strlen(add) + 1, 1);
		if (!base)
			return (NULL);
		i = -1;
		while (add[++i])
			base[i] = add[i];
		return (base);
	}
	return (base);
}

char	*ft_strjoin(char *base, char *add)
{
	char	*joined;
	int		i;
	int		j;

	if (!add || !*add || !base)
		return (join_edgecase(base, add));
	joined = ft_calloc(ft_strlen(base) + ft_strlen(add) + 1, 1);
	if (!joined)
		return (NULL);
	i = 0;
	j = 0;
	while (base[i])
		joined[j++] = base[i++];
	i = 0;
	while (add[i])
		joined[j++] = add[i++];
	joined[j] = '\0';
	free(base);
	return (joined);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;
	size_t	total;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total)
		ptr[i++] = 0;
	return (ptr);
}
