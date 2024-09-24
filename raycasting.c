/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:15:24 by alli              #+#    #+#             */
/*   Updated: 2024/09/24 16:50:22 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	find_angle(t_game *game)
{
	if (game->map[game->player_y][game->player_x]  == 'N')
		game->raycast->player_angle = NORTH;
	if (game->map[game->player_y][game->player_x] == 'S')
		game->raycast->player_angle = SOUTH;
	if (game->map[game->player_y][game->player_x] == 'W' )
		game->raycast->player_angle = WEST;
	if (game->map[game->player_y][game->player_x] == 'E')
		game->raycast->player_angle = EAST;
	game->raycast->p_x = (game->player_x * SQ_SIZE) + SQ_SIZE / 2; //place player in the middle of the sq
	game->raycast->p_y = (game->player_y * SQ_SIZE) + SQ_SIZE / 2;
	game->raycast->player_fov = (FOV * PI / 180);
}

int wall_hit(float x, float y, t_game *game)
{
	size_t	map_y;
	size_t	map_x;

	if (x < 0 || y < 0)
		return (1);
	map_y = floor(y / SQ_SIZE); //one grid square, indice where it's locaated 
	map_x = floor(x / SQ_SIZE);
	if(game->width <= map_x || game->height <= map_y)
		return (1);
	if (game->map[map_y] && map_x <= ft_strlen(game->map[map_y])) //making sure the coordinate exists
		if (game->map[map_y][map_x] == '1')
			return (1);
	return (0);
}

int	move_ray_dir(float angle, float *inter, float *step, int is_vert)
{//moves the ray along and tells the ray how to go through the grid (up down, left right)
	if (!is_vert) //horizontal
	{
		if (angle > WEST && angle < EAST) //ray pointing south
		{
			*inter += SQ_SIZE; //go south
			return (-1);
		}
		*step *= -1; //else going north
	}
	else
	{
		if (!(angle > SOUTH && angle < NORTH)) //going east
		{
			*inter += SQ_SIZE;
			return (-1);
		}
		*step *= -1; //else pointing west
	}
	return (1);
}

float	h_intersect(t_game *game, float angle)
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
	y = floor(game->raycast->p_y / SQ_SIZE) * SQ_SIZE; //nearest horizontal line below player's y position.
	move_ray = move_ray_dir(angle, &y, &y_step, 0);
	x = game->raycast->p_x + (y - game->raycast->p_y) / tan(angle); //moves the ray along the x axis
	if (angle > SOUTH && angle < NORTH)  // make sure it's moving left
        x_step = -fabs(x_step);
    else  // Moving right
        x_step = fabs(x_step);
	while (!wall_hit (x, y - move_ray, game))
	{
		x += x_step;
		y += y_step;
	}
	game->raycast->h_inter_x = x;
	game->raycast->h_inter_y = y;
	return (sqrt(pow(x - game->raycast->p_x, 2) + pow(y - game->raycast->p_y, 2)));
}

float	v_intersect(t_game *game, float angle)
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
	x = floor(game->raycast->p_x / SQ_SIZE) * SQ_SIZE;//calculates which tile the player stands on multiplying gets the top edge of tile
	move_ray = move_ray_dir(angle, &x, &x_step, 1);
	y = game->raycast->p_y + (x - game->raycast->p_x) * tan(angle); //moves the ray along the y axis
	if (angle > WEST && angle < EAST)  // Moving left
        y_step = fabs(y_step);
    else  // Moving right
        y_step = -fabs(y_step);
	while (!wall_hit(x - move_ray, y, game))
	{
		x += x_step;
		y += y_step;
	}
	game->raycast->v_inter_x = x;
	game->raycast->v_inter_y = y;
	return (sqrt(pow(x - game->raycast->p_x, 2) + pow(y - game->raycast->p_y, 2)));
}

void	cast_rays(t_game *game)
{
	double	h_inter; //closest x intersection
	double	v_inter; //closest y intersection
	int		ray;

	ray = 0;
	game->raycast->ray_angle = game->raycast->player_angle - (game->raycast->player_fov / 2);//have to initialize player_fov
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

void	math_to_display(void *data) //void	math_to_display(void *dis)
{
	t_game *game;

	game = (t_game *) data;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	move_hook(game);
	cast_rays(game);
}

