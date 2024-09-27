NAME = cub3D
BONUS_NAME = cub3D_bonus

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

MLX_DIR = ./MLX42
MLX42 = ./MLX42/build/libmlx42.a

SRCS_DIR = src
BONUS_DIR = bonus

INCLUDE = -I include

SRCS =  $(addprefix $(SRCS_DIR)/,main.c \
		check_map_info.c \
		color.c \
		copy_2darray.c \
		create_2darray.c \
		draw_wall_utils.c \
		draw_wall.c \
		free_grid.c \
		get_position.c \
		ft_atol.c \
		is_map_closed.c \
		check_empty_line.c \
		parse_elements.c \
		clean_up.c \
		init_game.c \
		map_validation.c \
		math_utils.c \
		move.c \
		move_direction.c \
		print_error.c \
		raycasting.c \
		run_game.c \
		set_map_info.c \
		set_colors.c \
		count_2darray_size.c \
		has_space.c \
		color_validation.c \
		set_flags.c)

BONUS = $(addprefix $(BONUS_DIR)/, main_bonus.c move_bonus.c)

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

CC = cc

HEADERS	= -I $(MLX_DIR)/include/MLX42

CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror -I./libft

RM = rm -f

all: makelibft $(NAME)

LDFLAGS = -L$(MLX_DIR)/build

LIBS = -lmlx42 -ldl -lglfw -pthread -lm

makelibft:
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(MLX42) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS) $(INCLUDE) $(HEADERS) $(LIBS) -L$(LIBFT_DIR) -lft

$(MLX42):
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) $(HEADERS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)
	rm -rf MLX42/build

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	$(RM) $(BONUS_OBJS)
	$(RM) $(BONUS_NAME)

bonus: $(BONUS_NAME) 

$(BONUS_NAME): $(BONUS_OBJS) $(MLX42) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(INCLUDE) $(HEADERS) $(MLX42) $(LIBS) $(LDFLAGS) -L$(LIBFT_DIR) -lft

re: fclean all

.PHONY: all clean fclean re makelibft
