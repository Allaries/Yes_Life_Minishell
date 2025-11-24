/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:03:59 by rerichar          #+#    #+#             */
/*   Updated: 2025/09/21 02:40:24 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(const char *s, char c)
{
	int	i;
	int	cmp;
	int	is_in_word;

	i = 0;
	cmp = 0;
	while (s[i])
	{
		is_in_word = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			if (is_in_word == 0)
			{
				cmp++;
				is_in_word = 1;
			}
			i++;
		}
	}
	return (cmp);
}

int	wordpos(const char *s, char c, int start)
{
	if (s[start] == c)
	{
		while (s[start] && s[start] == c)
			start++;
		return (start);
	}
	if (s[start] != c)
	{
		while (s[start] && s[start] != c)
			start++;
		return (start);
	}
	return (start);
}

char	**free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**fill_split(char *s, char c, char **arr, int i)
{
	int	j;
	int	start;
	int	end;

	j = 0;
	end = 0;
	start = 0;
	while (j < i)
	{
		if (j != 0 || s[start] == c)
			start = wordpos(s, c, end);
		end = wordpos(s, c, start);
		arr[j] = ft_substr(s, start, end - start);
		if (arr[j] == NULL)
			return (free_split(arr));
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char *s, char c)
{
	char	**arr;
	int		i;

	if (!s)
		return (NULL);
	i = count_word(s, c);
	arr = malloc(sizeof(char *) * (i + 1));
	if (arr == NULL)
		return (NULL);
	return (fill_split(s, c, arr, i));
}
