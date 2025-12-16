/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:46:31 by rerichar          #+#    #+#             */
/*   Updated: 2025/12/16 03:01:05 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdio.h>
// # include "../pipox/pipex.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>

char	*get_next_line(int fd);
// int		ft_strlen(char *str);
// void	*ft_calloc(size_t nmemb, size_t size);
// char	*ft_strjoin(char *base, char *add);
char	*join_edgecase(char *base, char *add);
char	*invalid_value(int fd, char *buff);
char	*overwrite(char *buff);
char	*giveline(char *buff);
int		nlcheck(char *buff);

#endif
