/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:15:24 by alli              #+#    #+#             */
/*   Updated: 2024/09/16 09:56:38 by alli             ###   ########.fr       */
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
	printf("after player_angle in find_angle: %f\n", game->raycast->player_angle);
	// printf("p_x: %f\n", game->raycast->p_x);
	// printf("p_y: %f\n", game->raycast->p_y);
	// printf("playr_angle = %f\n", game->raycast->player_angle);
	//printf("player fov = %d\n", game->raycast->player_fov);
}

void	find_mvmnt(t_raycast *ray)
{
	double	move_x;
	double	move_y;
	
	// move_x = 0;
	// move_y = 0;
	if (ray->player_rotation == -1)
	{
		printf("break\n");
	}
		// rotate_player(game, ray);
	if (ray->player_rotation == 1)
	{
		printf("break\n");
	}
		// rotate_player(game, ray);
	if (ray->left_right == 1) //moving right
	{
		move_x = -sin(ray->player_angle) * PLAYER_SPEED;
		move_y = cos(ray->player_angle) * PLAYER_SPEED;
	}
	if (ray->left_right == -1) //moving left
	{
		move_x = sin(ray->player_angle) * PLAYER_SPEED;
		move_y = -cos(ray->player_angle) * PLAYER_SPEED;
	}
	if (ray->up_down == -1) //moving up
	{
		move_x = -sin(ray->player_angle) * PLAYER_SPEED;
		move_y = -cos(ray->player_angle) * PLAYER_SPEED;
	}
	if (ray->up_down == 1) //moving down
	{
		move_x = sin(ray->player_angle) * PLAYER_SPEED;
		move_y = cos(ray->player_angle) * PLAYER_SPEED;
	}
}

int	check_ray_dir(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < PI) //left right
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (PI / 2) && angle < (3 * PI / 2)) // up down
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
	if (!is_vert)
	{
		if (angle > 0 && angle < PI) //pointing right or left
		{
			*inter += SQ_SIZE;
			return (-1);
		}
		*step *= -1; //Alice should understand
	}
	else
	{
		if (!(angle > PI / 2 && angle < 3 * PI / 2)) //pointing up or down
		{
			*inter += SQ_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

/*int	check_ray_dir(float angle, char c)
{
    // Check for horizontal direction (x-axis)
	if (c == 'x')
	{
        // Moving right (0 to PI/2 or 3 * PI/2 to 2 * PI)
		if (angle < PI / 2 || angle > 3 * PI / 2)
			return (1); // Right direction
        // Moving left (PI/2 to 3 * PI/2)
		else
			return (0); // Left direction
	}
    
    // Check for vertical direction (y-axis)
	if (c == 'y')
	{
        // Moving down (0 to PI)
		if (angle > 0 && angle < PI)
			return (1); // Down direction
        // Moving up (PI to 2 * PI)
		else
			return (0); // Up direction
	}
    
	return (0);
}*/


float	h_intersect(t_game *game, float angle)
{
	float	x_step;
	float	y_step;
	float	x;
	float	y;
	int	move_ray;
	
	// printf("before angle: %f\n", angle);
	x_step = SQ_SIZE / tan(angle);
	y_step = SQ_SIZE;
	y = floor(game->raycast->p_y / SQ_SIZE) * SQ_SIZE; //nearest horizontal line below player's y position.
	// printf("y = %f\n", y);
	move_ray = move_ray_dir(angle, &y, &y_step, 1);
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
	return (sqrt(pow(x - game->raycast->p_x, 2) + pow(y - game->raycast->p_y, 2)));
}

float	v_intersect(t_game *game, float angle)
{
	float	x_step;
	float	y_step;
	float	x;
	float	y;
	int		move_ray;
	
	x_step = SQ_SIZE;
	y_step = SQ_SIZE * tan(angle);
	x = floor(game->raycast->p_x / SQ_SIZE) * SQ_SIZE;//calculates which tile the player stands on multiplying gets the top edge of tile
	move_ray = move_ray_dir(angle, &x, &x_step, 0);
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
		game->raycast->is_horizon = 0;
		h_inter = h_intersect(game, adjust_angle(game->raycast->ray_angle));
		v_inter = v_intersect(game, adjust_angle(game->raycast->ray_angle));
		if (v_inter <= h_inter)
		{
			game->raycast->distance = v_inter;
			// if (game->raycast->ray_angle > 0)
			// game->raycast->wall_side = WEST_WALL;
			// printf("distance of v_inter: %f\n", game->raycast->distance);
		}
		else
		{
			game->raycast->distance = h_inter;
			game->raycast->is_horizon = 1;
		}
		render_wall(game, ray);
		ray++;
		// printf("before ray_angle: %f\n", game->raycast->ray_angle);
		// printf("player_fov: %f\n", game->raycast->player_fov);
		// printf("player_fov: %d\n", game->raycast->player_fov);
		// printf("adjustment: %f\n", game->raycast->player_fov / WINDOW_WIDTH);
		game->raycast->ray_angle += (game->raycast->player_fov / WINDOW_WIDTH);
		// printf("after ray_angle: %f\n", game->raycast->ray_angle);
	}
}

void	math_to_display(void *data) //void	math_to_display(void *dis)
{
	t_game *game;

	game = (t_game *) data;
	// game->raycast = malloc(sizeof(t_raycast));
	// find_angle(game);
	find_mvmnt(game->raycast);
	//move_player
	cast_rays(game);
}

