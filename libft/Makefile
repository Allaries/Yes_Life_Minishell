# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rerichar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 19:52:59 by rerichar          #+#    #+#              #
#    Updated: 2025/05/04 05:29:48 by rerichar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wall -Wextra
NAME = libft.a
SRC = ft_atoi.c ft_isascii.c  ft_memcmp.c ft_putendl_fd.c  ft_strdup.c\
	 ft_strlen.c ft_substr.c ft_bzero.c ft_isdigit.c  ft_memcpy.c\
   	 ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_tolower.c ft_calloc.c\
      	 ft_isprint.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c\
      	 ft_strnstr.c ft_toupper.c ft_isalnum.c ft_itoa.c ft_memset.c\
   	 ft_split.c ft_strlcat.c ft_strrchr.c ft_isalpha.c ft_memchr.c\
      	 ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strtrim.c ft_strncmp.c\

SRC_BONUS =	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c\
		 ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstdelone_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf *.o

bonus : $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean all re
