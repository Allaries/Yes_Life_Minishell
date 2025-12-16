/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:04:55 by smedenec          #+#    #+#             */
/*   Updated: 2025/07/02 15:04:20 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		lenbuff;
	char		*buff;
	char		*ligne;
	static char	*past = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 268435408)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	lenbuff = 1;
	while (!ft_strchr(past, '\n') && lenbuff > 0)
	{
		lenbuff = read(fd, buff, BUFFER_SIZE);
		if (lenbuff == -1)
			return (fail(&past, buff));
		buff[lenbuff] = '\0';
		past = ft_strjoin(past, buff);
	}
	free(buff);
	buff = NULL;
	ligne = take_line(past);
	past = save_rest(past);
	return (ligne);
}

char	*take_line(char *past)
{
	size_t	i;
	char	*ligne;

	i = 0;
	ligne = ft_strdup(past);
	if (!ligne)
		return (NULL);
	if (ligne[0] == 0)
		return (free(ligne), NULL);
	while (ligne && ligne[i] && (ligne[i] != '\n'))
		i++;
	if (ligne[i] == '\n')
		i++;
	ligne[i] = '\0';
	return (ligne);
}

char	*save_rest(char *past)
{
	char	*rest;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (past && past[i] && past[i] != '\n')
		i++;
	if (!past || !past[i] || (past[i] == '\n' && !past[i + 1]))
		return (fail(&past, 0));
	i++;
	len = ft_strlen(past);
	rest = malloc(sizeof(char) * (len + 1 - i));
	if (!rest)
		return (fail(&past, 0));
	while (past[i + j])
	{
		rest[j] = past[i + j];
		j++;
	}
	rest[j] = '\0';
	free(past);
	past = NULL;
	return (rest);
}

void	*fail(char	**past, char *buff)
{
	free(buff);
	free(*past);
	*past = NULL;
	return (NULL);
}
// int	main(void)
// {
// 	int		i;
// 	int		file;
// 	char	*line;
// 	i = 0;
// 	file = open("file.txt", O_RDONLY);
// 	if (file == -1)
// 	{
// 		printf("Fail to open file\n");
// 		return (1);
// 	}
// 	while (++i <= 8)
// 	{
// 		line = get_next_line(file);
// 		if (!line)
// 			printf("Call %d = (null)\n", i);
// 		else
// 			printf("Call %d = %s", i, (char *)line);
// 		free(line);
// 		line = NULL;
// 	}
// 	close(file);
// 	return (0);
// }
