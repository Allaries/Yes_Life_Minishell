CC = cc
CFLAGS = -Werror -Wall -Wextra
NAME = gnl.a
SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf *.o

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean all re
