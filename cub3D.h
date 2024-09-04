/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:24:37 by mito              #+#    #+#             */
/*   Updated: 2024/09/04 12:36:32 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define PI 3.14159265
# define FOV 60


# include "./libft/libft.h"
# include "MLX42.h"

# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h> // for printf, delete it
# include <math.h>

# define WINDOW_WIDTH 640 // change it
# define WINDOW_HEIGHT 480 // change it
# define PLAYER_SPEED	0.045
# define SQ_SIZE 10
# define PI 3.14159265
# define FOV 60

typedef struct s_flags
{
	int no;
	int so;
	int we;
	int ea;
	int f;
	int c;
	int all_flags;
}	t_flags;

typedef struct s_raycast
{
	double	player_angle;
	int		player_rotation; //have to initialize this
	int		up_down;
	int		left_right;
}	t_raycast;

typedef struct s_game
{
	//char	*filename; // do we need it?
	char		**map;
	char		**file_copy;
	t_flags 	*info_flags;
	char		*no_tex_path;
	char		*so_tex_path;
	char		*we_tex_path;
	char		*ea_tex_path;
	char		*floor_rgb;
	char		*ceiling_rgb;
	size_t		height;
	// size_t	width; do we need it?
	size_t		player_x;
	size_t		player_y;
	mlx_t		*mlx;
	mlx_image_t	*canvas; // image
	mlx_texture_t	*no_texture;
	mlx_texture_t	*so_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*ea_texture;
	t_raycast		*raycast;
}				t_game;

void	print_error_exit(char *message);
void	init_game(t_game *game, char *map);
char	**create_2darray(char *map_file);
int		check_map_info(char **map, t_flags *flags);
char	**copy_2darray(char **src);
void	free_grid(char **grid);
void    set_map_info(t_game *game, char **file_copy);
int		map_validation(t_game *game, char **map);
int		count_2darray_size(char **src);
int 	run_game(t_game *game);
int		check_colors(char *color_str);
unsigned int	color(int r, int g, int b, int a);
int		check_colors(char *color_str);

#endif
