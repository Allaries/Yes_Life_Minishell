CC = cc
CFLAGS = -Wall -Wextra -g3 -g
LDFLAGS = -lreadline -lhistory -lncurses
NAME = minishell

SRC = main.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)
	@echo "Ready"

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf *.o
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@echo "Clean"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@echo "All clean"

re: fclean all

.PHONY: all clean fclean re
