/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:24:37 by mito              #+#    #+#             */
/*   Updated: 2024/09/26 16:23:57 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "MLX42.h"

# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
# define PLAYER_SPEED 3
# define ROTATE_SPEED 0.045
# define SQ_SIZE 64
# define PI 3.14159265
# define FOV 60

# define NORTH 3 * PI / 2.0f
# define SOUTH PI / 2.0f
# define EAST PI
# define WEST 0

typedef struct s_flags
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
	int	all_flags;
}	t_flags;

typedef struct s_raycast
{
	double	player_angle;
	double	player_rotation;
	double	player_fov; //have to initialize this
	int		p_x;
	int		p_y;
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
	char			**map;
	char			**file_copy;
	t_flags			*info_flags;
	char			*no_tex_path;
	char			*so_tex_path;
	char			*we_tex_path;
	char			*ea_tex_path;
	char			*floor_rgb;
	char			*ceiling_rgb;
	size_t			height;
	size_t			width;
	uint32_t		floor_r;
	uint32_t		floor_g;
	uint32_t		floor_b;
	uint32_t		ceiling_r;
	uint32_t		ceiling_g;
	uint32_t		ceiling_b;
	size_t			player_x;
	size_t			player_y;
	mlx_t			*mlx;
	mlx_image_t		*canvas;
	mlx_texture_t	*no_texture;
	mlx_texture_t	*so_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*ea_texture;
	t_raycast		*raycast;
}				t_game;

void		print_error_exit(char *message);
void		print_error(char *message);
void		init_game(t_game *game, char *map);
char		**create_2darray(char *map_file);
int			check_map_info(char **map, t_flags *flags);
char		**copy_2darray(char **src);
void		free_grid(char **grid);
int			set_map_info(t_game *game, char **file_copy);
int			map_validation(t_game *game, char **map);
int			count_2darray_size(char **src);
int			run_game(t_game *game);
void		get_position(t_game *game, char **map);
int			is_str_digit(char *str);
long		ft_atol(const char *str);
uint32_t	color(uint32_t r, uint32_t g, uint32_t b);
int			is_map_closed(t_game *game, char **map);

int		check_empty_line(t_game *game, char *map_file);
int		parse_elements(t_game *game, char *map_file);
void	set_fc_colors(t_game *game, char *c_color, char *f_color);
int		has_space(char *str);
int color_validation(char **color_split);

/*raycasting*/
void	math_to_display(void *game);
void	render_wall(t_game *game, int ray);
float	adjust_angle(double angle);
// int		wall_hit(float x, float y, t_game *game);
void	cast_rays(t_game *game);
void	find_angle(t_game *game);
float	distance(t_game *game,float x, float y);
double get_x_offset(mlx_texture_t *texture, t_game *game);
int		check_texture(mlx_texture_t *texture);
int	norm_color(int c);

/*movement*/
void	move_hook(t_game *game);
void	mouse_movement(double xpos, double ypos, void *data);
void	move_player(t_game *game, double move_x, double move_y);
void	for_or_back(t_game *game, char key);
void	left_or_right(t_game *game, char key);
void	rotate(t_game *game, char key);
int			check_empty_line(t_game *game, char *map_file);
int			parse_elements(t_game *game, char *map_file);
int			has_space(char *str);
int			color_validation(char **color_split);
int			set_flags(char *line, t_flags *flags);

/*raycasting*/
void		math_to_display(void *game);
void		render_wall(t_game *game, int ray);
float		adjust_angle(double angle);
void		cast_rays(t_game *game);
void		find_angle(t_game *game);
float		distance(t_game *game, float x, float y);

/*movement*/
void		move_hook(t_game *game);
void		mouse_movement(double xpos, double ypos, void *data);

void		clean_up_exit(t_game *game, char *message);
void		clean_up(t_game *game);

#endif
