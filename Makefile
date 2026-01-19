CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline -lhistory -lncurses
NAME = minishell
SRC = main.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = ./gnl
GNL = $(GNL_DIR)/gnl.a

all: $(LIBFT) $(GNL) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(GNL) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	clear

re: fclean all

.PHONY: all clean fclean re
