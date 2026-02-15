CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LDFLAGS = -lreadline -lhistory -lncurses
NAME = minishell
SRC =   ptitecoquille/pipex.c ptitecoquille/childs.c \
		ptitecoquille/for_free.c ptitecoquille/fd.c \
		ptitecoquille/environment.c ptitecoquille/built_in/*c \
		parsing/parsing.c parsing/expend/*c parsing/free/*c \
		parsing/list_cmd/*c parsing/list_token/*c parsing/utils.c \
		main.c \

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
