/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:24:37 by mito              #+#    #+#             */
/*   Updated: 2024/09/11 15:34:38 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "MLX42.h"

# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h> // for printf, delete it
# include <math.h>

# define WINDOW_WIDTH 640 // change it
# define WINDOW_HEIGHT 480 // change it
# define PLAYER_SPEED 0.045
# define SQ_SIZE 32
# define PI 3.14159265
# define FOV 60
# define VFOV 90

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
	double	player_rotation;
	double		player_fov; //have to initialize this
	int	p_x;
	int	p_y;
	int		up_down;
	int		left_right;
	double	ray_angle;
	float	h_inter_x;
	float	h_inter_y;
	float	v_inter_x;
	float	v_inter_y;
	double	distance;
	bool	is_horizon;
	int		index;
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
	size_t		width;
	uint32_t			floor_r; //temp
	uint32_t			floor_g; //temp
	uint32_t			floor_b; //temp
	uint32_t			ceiling_r; //temp
	uint32_t			ceiling_g; //temp
	uint32_t			ceiling_b; //temp
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
void	get_position(t_game *game, char **map);
int		is_str_digit(char *str);
long	ft_atol(const char *str);
//unsigned int	color(int r, int g, int b, int a);
uint32_t	color(uint32_t r, uint32_t g, uint32_t b);
int		set_ceiling_colors(t_game *game, char *color_str);
int		set_floor_colors(t_game *game, char *color_str);

/*raycasting*/
void	math_to_display(void *game);
void	render_wall(t_game *game, int ray);
float	adjust_angle(double angle);
int		wall_hit(float x, float y, t_game *game);
void	cast_rays(t_game *game);

/*movement*/
void	move_hook(void *data);

#endif
