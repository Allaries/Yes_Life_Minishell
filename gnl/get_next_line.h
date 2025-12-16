/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerichar <rerichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:19:34 by smedenec          #+#    #+#             */
/*   Updated: 2025/12/16 05:58:45 by rerichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../pipox/pipex.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stddef.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 77
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*take_line(char *past);
char	*save_rest(char *past);
void	*fail(char **past, char *buff);
// size_t	ft_strlen(const char *str);
// char	*ft_strdup(const char *s);
// char	*ft_strchr(const char *s, int c);

#endif
