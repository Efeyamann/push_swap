NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I includes -I libft -I ft_printf

SRC_DIR = main
OPS_DIR = operations
UTILS_DIR = utils
LIBFT_DIR = libft
PRINTF_DIR = ft_printf

SRC_FILES = $(SRC_DIR)/main.c \
            $(SRC_DIR)/initialize_stack.c \
            $(OPS_DIR)/push.c \
            $(OPS_DIR)/rotate.c \
            $(OPS_DIR)/reverse_rotate.c \
            $(OPS_DIR)/swap.c \
            $(UTILS_DIR)/utils.c

OBJ = $(SRC_FILES:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re