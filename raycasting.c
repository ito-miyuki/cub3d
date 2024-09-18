/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:15:24 by alli              #+#    #+#             */
/*   Updated: 2024/09/18 11:05:38 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	find_angle(t_game *game)
{
	if (game->map[game->player_y][game->player_x]  == 'N')
		game->raycast->player_angle = 3 * PI / 2;
	if (game->map[game->player_y][game->player_x] == 'S')
		game->raycast->player_angle = PI / 2;
	if (game->map[game->player_y][game->player_x] == 'W' )
		game->raycast->player_angle = PI;
	if (game->map[game->player_y][game->player_x] == 'E')
		game->raycast->player_angle = 0;
	game->raycast->p_x = (game->player_x * SQ_SIZE) + SQ_SIZE / 2; //place player in the middle of the sq
	game->raycast->p_y = (game->player_y * SQ_SIZE) + SQ_SIZE / 2;
	game->raycast->player_fov = (FOV * PI / 180);
	// printf("after player_angle in find_angle: %f\n", game->raycast->player_angle);
	// printf("p_x: %f\n", game->raycast->p_x);
	// printf("p_y: %f\n", game->raycast->p_y);
	// printf("playr_angle = %f\n", game->raycast->player_angle);
	//printf("player fov = %d\n", game->raycast->player_fov);
}

int	check_ray_dir(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < PI) //headed south
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > PI / 2 && angle < 3 * PI / 2) //headed east
			return (1);
	}
	return (0);
}

int wall_hit(float x, float y, t_game *game)
{
	size_t	map_y;
	size_t	map_x;

	if (x < 0 || y < 0)
		return (1);
	// printf("wall_hit x: %f\n", x / SQ_SIZE);
	// printf("wall_hit y: %f\n", y/ SQ_SIZE);
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
		if (angle > 0 && angle < PI) //ray pointing south
		{
			*inter += SQ_SIZE; //going to the next grid size
			return (-1);
		}
		*step *= -1; //else going north
	}
	else
	{
		if (!(angle > PI / 2 && angle < 3 * PI / 2)) //going east
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

	// printf("before angle: %f\n", angle);
	if (angle == 0)
		angle = 0.00001;
	x_step = SQ_SIZE / tan(angle);
	y_step = SQ_SIZE;
	y = floor(game->raycast->p_y / SQ_SIZE) * SQ_SIZE; //nearest horizontal line below player's y position.
	// printf("y = %f\n", y);
	move_ray = move_ray_dir(angle, &y, &y_step, 0);
	// printf("player_x %d\n", game->raycast->p_x);
	x = game->raycast->p_x + (y - game->raycast->p_y) / tan(angle); //moves the ray along the x axis
	// if (angle > PI / 2 && angle < 3 * PI / 2)  // Moving left
    //     x_step = -fabs(x_step);
    // else  // Moving right
    //     x_step = fabs(x_step);
	if ((check_ray_dir(angle, 'y') && (x_step > 0)) //down and right correct it by flipping x_step
		 || (!check_ray_dir(angle, 'y') && x_step < 0)) //pointing up and left might want it to move right instead gotta flip
		x_step *= -1;
	while (!wall_hit (x, y - move_ray, game))
	{
		// printf("wall hit\n");
		x += x_step;
		y += y_step;
	}
	game->raycast->h_inter_x = x;
	game->raycast->h_inter_y = y;
	// printf("h_inter x: %f\n", x);
	// printf("h_inter y: %f\n", y);
	// printf("distance for h _inter %f\n", sqrt(pow(x - game->raycast->p_x, 2) + pow(y - game->raycast->p_y, 2)));
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
	if ((check_ray_dir(angle, 'x') && (y_step < 0)) //right and up (so make it go down)
			|| (!check_ray_dir(angle, 'x') && y_step > 0)) //moving left and down (make it go up)
				y_step *= -1;
	while (!wall_hit(x - move_ray, y, game))
	{
		x += x_step;
		y += y_step;
	}
	game->raycast->v_inter_x = x;
	game->raycast->v_inter_y = y;
	// printf("distance for v_inter %f\n", sqrt(pow(x - game->raycast->p_x, 2) + pow(y - game->raycast->p_y, 2)));
	return (sqrt(pow(x - game->raycast->p_x, 2) + pow(y - game->raycast->p_y, 2)));
}

void	cast_rays(t_game *game)
{
	double	h_inter; //closest x intersection
	double	v_inter; //closest y intersection
	int		ray;

	ray = 0; //left most to right most ray

	// printf("player_angle: %f\n", game->raycast->player_angle);
	game->raycast->ray_angle = game->raycast->player_angle - (game->raycast->player_fov / 2);//have to initialize player_fov
	while (ray < WINDOW_WIDTH)
	{
		// printf("Window width: %d\n", WINDOW_WIDTH);
		// printf("ray: %d\n", ray);
		game->raycast->is_horizon = 0;
		h_inter = h_intersect(game, adjust_angle(game->raycast->ray_angle));
		v_inter = v_intersect(game, adjust_angle(game->raycast->ray_angle));
		// printf("distance of v_inter: %f\n", game->raycast->distance / SQ_SIZE);
		// printf("distance of h_inter: %f\n", game->raycast->distance / SQ_SIZE);
		if (v_inter <= h_inter)
		{
			game->raycast->distance = v_inter;
			// if (game->raycast->ray_angle > 0)
			// game->raycast->wall_side = WEST_WALL;
			// printf("distance of v_inter\n");
		}
		else
		{
			game->raycast->distance = h_inter;
			game->raycast->is_horizon = 1;
			// printf("distance of h_inter: %f\n", game->raycast->distance / SQ_SIZE);
		}
		render_wall(game, ray);
		ray++;
		// printf("before ray_angle: %f\n", game->raycast->ray_angle);
		// printf("player_fov: %f\n", game->raycast->player_fov);
		// printf("player_fov: %d\n", game->raycast->player_fov);
		// printf("adjustment: %f\n", game->raycast->player_fov / WINDOW_WIDTH);
		game->raycast->ray_angle += (game->raycast->player_fov / WINDOW_WIDTH);
		// printf("player_angle: %f\n", game->raycast->player_angle);
		// printf("after ray_angle: %f\n", game->raycast->ray_angle);
	}
}

void	math_to_display(void *data) //void	math_to_display(void *dis)
{
	t_game *game;

	game = (t_game *) data;
	//move_player
	cast_rays(game);
}

