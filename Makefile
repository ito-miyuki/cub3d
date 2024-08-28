NAME = cub3d

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

MLX_DIR = ./MLX42
MLX42 = ./MLX42/build/libmlx42.a

SRCS =	main.c \
		print_error.c \
		init_map.c

OBJS = $(SRCS:.c=.o)

CC = cc

HEADERS	= -I $(MLX_DIR)/include/MLX42

CFLAGS = -Wall -Wextra -Werror -I./libft

RM = rm -f

all: makelibft $(NAME)

LDFLAGS = -L$(MLX_DIR)/build

LIBS = -lmlx42 -ldl -lglfw -pthread -lm

makelibft:
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(MLX42) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS) $(HEADERS) $(LIBS) -L$(LIBFT_DIR) -lft

$(MLX42):
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)
	rm -rf MLX42/build

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re makelibft
