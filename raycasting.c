/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:15:24 by alli              #+#    #+#             */
/*   Updated: 2024/09/25 10:28:55 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int wall_hit(float x, float y, t_game *game)
{
	size_t	map_y;
	size_t	map_x;

	if (x < 0 || y < 0)
		return (1);
	map_y = floor(y / SQ_SIZE);
	map_x = floor(x / SQ_SIZE);
	if(game->width <= map_x || game->height <= map_y)
		return (1);
	if (game->map[map_y] && map_x <= ft_strlen(game->map[map_y]))
		if (game->map[map_y][map_x] == '1')
			return (1);
	return (0);
}

static int	move_ray_dir(float angle, float *inter, float *step, int is_vert)
{
	if (!is_vert)
	{
		if (angle > WEST && angle < EAST)
		{
			*inter += SQ_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > SOUTH && angle < NORTH))
		{
			*inter += SQ_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

static float	h_intersect(t_game *game, float angle)
{
	float	x_step;
	float	y_step;
	float	x;
	float	y;
	int	move_ray;

	if (angle == 0)
		angle = 0.00001;
	x_step = SQ_SIZE / tan(angle);
	y_step = SQ_SIZE;
	y = floor(game->raycast->p_y / SQ_SIZE) * SQ_SIZE;
	move_ray = move_ray_dir(angle, &y, &y_step, 0);
	x = game->raycast->p_x + (y - game->raycast->p_y) / tan(angle);
	if (angle > SOUTH && angle < NORTH)
        x_step = -fabs(x_step);
    else
		x_step = fabs(x_step);
	while (!wall_hit (x, y - move_ray, game))
	{
		x += x_step;
		y += y_step;
	}
	game->raycast->h_inter_x = x;
	game->raycast->h_inter_y = y;
	return (distance(game, x, y));
}

static float	v_intersect(t_game *game, float angle)
{
	float	x_step;
	float	y_step;
	float	x;
	float	y;
	int		move_ray;
	
	if (angle == 0)
		angle = 0.00001;
	x_step = SQ_SIZE;
	y_step = SQ_SIZE * tan(angle);
	x = floor(game->raycast->p_x / SQ_SIZE) * SQ_SIZE;
	move_ray = move_ray_dir(angle, &x, &x_step, 1);
	y = game->raycast->p_y + (x - game->raycast->p_x) * tan(angle);
	if (angle > WEST && angle < EAST)  // Moving left
        y_step = fabs(y_step);
    else
		y_step = -fabs(y_step);	
	while (!wall_hit(x - move_ray, y, game))
	{
		x += x_step;
		y += y_step;
	}
	game->raycast->v_inter_x = x;
	game->raycast->v_inter_y = y;
	return (distance(game, x, y));
}

void	cast_rays(t_game *game)
{
	double	h_inter;
	double	v_inter;
	int		ray;

	ray = 0;
	game->raycast->ray_angle = game->raycast->player_angle - (game->raycast->player_fov / 2);
	while (ray < WINDOW_WIDTH)
	{
		game->raycast->ray_angle = adjust_angle(game->raycast->ray_angle);
		game->raycast->is_horizon = 0;
		h_inter = h_intersect(game, game->raycast->ray_angle);
		v_inter = v_intersect(game, game->raycast->ray_angle);
		if (v_inter <= h_inter)
			game->raycast->distance = v_inter;
		else
		{
			game->raycast->distance = h_inter;
			game->raycast->is_horizon = 1;
		}
		render_wall(game, ray);
		ray++;
		game->raycast->ray_angle += (game->raycast->player_fov / WINDOW_WIDTH);
	}
}

