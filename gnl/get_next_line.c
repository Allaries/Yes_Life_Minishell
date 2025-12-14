/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:16:46 by rerichar          #+#    #+#             */
/*   Updated: 2025/06/20 15:33:12 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*overwrite(char *buff)
{
	int	i;
	int	j;

	if (!buff)
		return (NULL);
	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	while (buff[i])
		buff[j++] = buff[i++];
	buff[j] = '\0';
	return (buff);
}

char	*giveline(char *buff)
{
	int		i;
	char	*line;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	overwrite(buff);
	return (line);
}

int	nlcheck(char *buff)
{
	int	i;

	i = 0;
	if (!buff)
		return (0);
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*invalid_value(int fd, char *buff)
{
	if (fd == -1)
	{
		free(buff);
		buff = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*temp;
	int			i;

	if (fd > 1024 || fd < 0 || BUFFER_SIZE <= 0)
		return (invalid_value(fd, buff));
	while (!nlcheck(buff))
	{
		temp = malloc(BUFFER_SIZE + 1);
		if (!temp)
			return (NULL);
		i = read(fd, temp, BUFFER_SIZE);
		if (i == -1)
			return (free(temp), free(buff), buff = NULL, NULL);
		temp[i] = '\0';
		buff = ft_strjoin(buff, temp);
		free(temp);
		if (!buff || i == 0)
			break ;
	}
	if (buff && *buff)
		return (giveline(buff));
	return (free(buff), buff = NULL, NULL);
}

// int	main(void)
// {
// 	int	fd;
// 	char	*str;

// 	fd = open("test2.txt", O_RDONLY);
// 	str  = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("%s", str);
// 		free (str);
// 		str = get_next_line(fd);
// 	}
// 	close (fd);
// }
