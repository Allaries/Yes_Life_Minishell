CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline -lhistory -lncurses
NAME = minishell
SRC = parsing/main.c parsing/build_list_token.c \
		parsing/parsing.c parsing/check_input.c \
		parsing/check_quote.c parsing/free.c \
		parsing/token_utils.c parsing/token.c \
		parsing/utils.c parsing/verify_list_token.c \
		parsing/word.c parsing/word_utils.c \
		parsing/build_list_cmd.c \

OBJDIR = obj
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = ./gnl
GNL = $(GNL_DIR)/gnl.a

all: $(LIBFT) $(GNL) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) $(GNL) $(LDFLAGS) -o $(NAME)
	@echo "All done !"

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(GNL):
	@$(MAKE) -s -C $(GNL_DIR)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(GNL_DIR) clean
	@echo "All clean !"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(GNL_DIR) fclean
	@echo "All clean ++!"

re: fclean all

.PHONY: all clean fclean re
