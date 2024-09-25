/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:33:46 by alli              #+#    #+#             */
/*   Updated: 2024/09/25 17:18:33 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static mlx_texture_t	*get_texture(t_game *game)
{
	if (game->raycast->is_horizon == 1)
	{
		if (game->raycast->ray_angle > WEST && game->raycast->ray_angle < EAST)  //facing south
			return (game->so_texture);
		else
			return (game->no_texture);
	}
	else
	{
		if (game->raycast->ray_angle > SOUTH
			&& game->raycast->ray_angle < NORTH)
			// return (game->ea_texture);
			return (game->ea_texture);
		else
			// return (game->we_texture);
			return (game->we_texture);
	}
}

void	draw_wall(t_game *game, double lower_p, double upper_p, double wall_h)
{
	mlx_texture_t	*texture;
	uint32_t		*pixels;
	double			x_o;
	double			y_o;
	int				tex_y;

	texture = get_texture(game);
	if (!check_texture(texture))
		return ;
	pixels = (uint32_t *)texture->pixels;
	x_o = get_x_offset(texture, game);
	y_o = (upper_p - (WINDOW_HEIGHT / 2) + (wall_h / 2))
		* (double)texture->height / wall_h;
	if (y_o < 0)
		y_o = 0;
	while (upper_p < lower_p)
	{
		tex_y = (int)y_o * texture->width + (int)x_o;
		mlx_put_pixel(game->canvas, game->raycast->index,
			upper_p, norm_color(pixels[tex_y]));
		y_o += (double)texture->height / wall_h;
		upper_p++;
	}
}

void	draw_floor_ceil(t_game *game, int ray, double lower_p, double upper_p)
{
	uint32_t	ceil;

	ceil = 0;
	while (ceil < upper_p)
	{
		mlx_put_pixel(game->canvas, ray, ceil,
			color(game->ceiling_r, game->ceiling_g, game->ceiling_b));
		ceil++;
	}
	while (lower_p < WINDOW_HEIGHT)
	{
		mlx_put_pixel(game->canvas, ray, lower_p,
			color(game->floor_r, game->floor_g, game->floor_b));
		lower_p++;
	}
}

void	render_wall(t_game *game, int ray)
{
	double	wall_h;
	double	lower_p;
	double	upper_p;

	wall_h = 0;
	game->raycast->distance *= cos(adjust_angle
			(game->raycast->player_angle - game->raycast->ray_angle));
	wall_h = fabs((SQ_SIZE / game->raycast->distance)
			* (WINDOW_WIDTH / 2) / tan(game->raycast->player_fov));
	lower_p = (WINDOW_HEIGHT / 2) + (wall_h / 2);
	upper_p = (WINDOW_HEIGHT / 2) - (wall_h / 2);
	if (lower_p > WINDOW_HEIGHT)
		lower_p = WINDOW_HEIGHT;
	if (upper_p < 0)
		upper_p = 0;
	game->raycast->index = ray;
	draw_wall(game, lower_p, upper_p, wall_h);
	draw_floor_ceil(game, ray, lower_p, upper_p);
}
