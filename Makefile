NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I includes -I libft -I main

SRC_DIR = main
OPS_DIR = operations
UTILS_DIR = utils
LIBFT_DIR = libft

SRC_FILES = $(SRC_DIR)/main.c \
			$(SRC_DIR)/push_swap.c \
			$(CHECK_AND_CREATE_DIR)/checks.c \
			$(CHECK_AND_CREATE_DIR)/create_list.c \
            $(OPS_DIR)/push.c \
            $(OPS_DIR)/rotate.c \
            $(OPS_DIR)/reverse_rotate.c \
            $(OPS_DIR)/swap.c \
            $(UTILS_DIR)/utils.c \
			$(UTILS_DIR)/free.c

OBJ = $(SRC_FILES:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re