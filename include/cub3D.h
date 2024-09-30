/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:24:37 by mito              #+#    #+#             */
/*   Updated: 2024/09/30 11:26:55 by alli             ###   ########.fr       */
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

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
# define PLAYER_SPEED 3
# define ROTATE_SPEED 0.045
# define SQ_SIZE 64
# define PI 3.14159265
# define FOV 60

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
	double	player_fov;
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

/*clean up*/
void		clean_up_exit(t_game *game, char *message);
void		clean_up(t_game *game);
void		delete_texture(t_game *game, char *message);

/*color*/
uint32_t	color(uint32_t r, uint32_t g, uint32_t b);
int			color_validation(char **color_split);
void		set_fc_colors(t_game *game, char *c_color, char *f_color);

/*draw wall*/
int			check_texture(mlx_texture_t *texture);
double		get_x_offset(mlx_texture_t *texture, t_game *game);
int			norm_color(int c);

/*error message*/
void		print_error_exit(char *message);
void		print_error(char *message);

/*movement*/
void		move_hook(t_game *game);
void		move_player(t_game *game, double move_x, double move_y);
void		for_or_back(t_game *game, char key);
void		left_or_right(t_game *game, char key);
void		rotate(t_game *game, char key);

/*parsing*/
int			check_empty_line(t_game *game, char *map_file);
int			check_map_info(char **map, t_flags *flags);
char		**copy_2darray(char **src);
int			count_2darray_size(char **src);
char		**create_2darray(char *map_file);
void		free_grid(char **grid);
long		ft_atol(const char *str);
void		get_position(t_game *game, char **map);
int			has_space(char *str);
void		init_game(t_game *game, char *map);
int			is_map_closed(t_game *game, char **map);
int			is_str_digit(char *str);
void		map_validation(t_game *game, char **map);
void		parse_elements(t_game *game, char *map_file);
void		run_game(t_game *game);
int			set_map_info(t_game *game, char **file_copy);
int			set_flags(char *line, t_flags *flags);

/*raycasting*/
float		adjust_angle(double angle);
void		cast_rays(t_game *game);
float		distance(t_game *game, float x, float y);
void		find_angle(t_game *game);
void		math_to_display(void *game);
void		render_wall(t_game *game, int ray);

#endif
