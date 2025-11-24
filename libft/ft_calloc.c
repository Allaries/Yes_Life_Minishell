/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:32:42 by rerichar          #+#    #+#             */
/*   Updated: 2025/05/04 03:40:21 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (0);
	if (nmemb * size == 0)
	{
		return (NULL);
	}
	ptr = malloc (sizeof (*ptr) * ((nmemb * size)));
	if (ptr == NULL)
		return (0);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}
