/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:15:24 by alli              #+#    #+#             */
/*   Updated: 2024/09/09 11:35:09 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void find_angle(t_game *game)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while(game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'N')
			{
				game->raycast->player_angle = 3 * PI / 2;
				break ;
			}
			if (game->map[y][x] == 'S')
			{
				game->raycast->player_angle = PI / 2;
				break ;
			}
			if (game->map[y][x] == 'W')
			{
				game->raycast->player_angle = 0;
				break ;
			}
			if (game->map[y][x] == 'E')
			{
				game->raycast->player_angle = PI;
				break ;
			}
			x++;
		}
		y++;
	}
	game->player_x = (game->player_x * SQ_SIZE) + SQ_SIZE / 2; //place player in the middle of the sq
	game->player_y = (game->player_y * SQ_SIZE) + SQ_SIZE / 2;
}

/*void	find_mvmnt(t_raycast *ray)
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
}*/

int	check_ray_dir(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < PI) //left right
			return (1);
	}
	if (c == 'y')
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

	map_y = floor(y / SQ_SIZE); //one grid square, indice where it's locaated 
	map_x = floor(x / SQ_SIZE);
	if (x < 0 || y < 0)
		return (1);
	if(game->width < map_x || game->height < map_y)
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

float	h_intersect(t_game *game, float angle)
{
	float	x_step;
	float	y_step;
	float	x;
	float	y;
	int	move_ray;
	
	x_step = SQ_SIZE / tan(angle);
	y_step = SQ_SIZE;
	y = floor (game->player_y / SQ_SIZE * SQ_SIZE); //nearest horizontal line below player's y position.
	move_ray = move_ray_dir(game->raycast->ray_angle, &y, &y_step, 1);
	x = game->player_x + (y - game->player_y) / tan(angle); //moves the ray along the x axis
	if ((check_ray_dir(angle, 'y') && (x_step > 0)) //down and right correct it by flipping x_step
		 || (!(check_ray_dir(angle, 'y') && (x_step < 0)))) //pointing up and left might want it to move right instead gotta flip
		x_step *= -1;
	while (!wall_hit (x, y - move_ray, game))
	{
		x += x_step;
		y += y_step;
	}
	game->raycast->h_inter_x = x;
	game->raycast->h_inter_y = y;
	return (sqrt(pow(x - game->player_x, 2) + pow(y - game->player_y, 2)));
}

float	v_intersect(t_game *game, float angle)
{
	float	x_step;
	float	y_step;
	float	x;
	float	y;
	int		move_ray;
	
	x_step = SQ_SIZE;
	y_step = SQ_SIZE / tan(angle);
	x = floor(game->player_x / SQ_SIZE) * SQ_SIZE;//calculates which tile the player stands on multiplying gets the top edge of tile
	move_ray = move_ray_dir(game->raycast->ray_angle, &x, &x_step, 0);
	y = game->player_y + (x - game->player_x) / tan(angle); //moves the ray along the y axis
	if ((check_ray_dir(angle, 'x') && (y_step < 0)) //right and up (so make it go down)
			|| (!(check_ray_dir(angle, 'x') && (y_step > 0)))) //moving left and down (make it go up)
				y_step *= -1;
	while (!wall_hit(y, x = move_ray, game))
	{
		x += x_step;
		y += y_step;
	}
	game->raycast->v_inter_x = x;
	game->raycast->v_inter_y = y;
	return (sqrt(pow(x - game->player_x, 2) + pow(y - game->player_y, 2)));
}

void	draw_wall(t_game *game, double lower_p, double upper_p, double wall_h)
{
    // uint32_t x;
    // uint32_t y;

    // x = game->raycast->index;
    // y = 0;
	
    while (upper_p < lower_p && lower_p < wall_h)
    {
        mlx_put_pixel(game->canvas, game->raycast->index, upper_p,
                color(178, 255, 102, 255));
        upper_p++;
    }
}

void	render_wall(t_game *game, int ray)
{
	double	wall_h;
	double	lower_p;
	double	upper_p;
	
	game->raycast->distance *= cos(game->raycast->ray_angle - game->raycast->player_angle);
	wall_h = (SQ_SIZE / game->raycast->distance) * (WINDOW_WIDTH / 2) / tan(game->raycast->player_fov / 2);
	lower_p = (WINDOW_HEIGHT / 2) + (wall_h / 2); //splits the screen in half and calcs the bottom wall
	upper_p = (WINDOW_HEIGHT / 2) - (wall_h / 2); //top part of the screen
	if (lower_p > WINDOW_HEIGHT)
		lower_p = WINDOW_HEIGHT;
	if (upper_p	< 0)
		upper_p = 0;
	game->raycast->index = ray;
	draw_wall(game, lower_p, upper_p, wall_h);
	//draw_wall
	//draw floor and ceiling
}

void	cast_rays(t_game *game)
{
	double	h_inter; //closest x intersection
	double	v_inter; //closest y intersection
	int		ray;

	ray = 0; //left most to right most ray
	game->raycast->ray_angle = game->raycast->player_angle - (game->raycast->player_fov / 2);
	while (ray < WINDOW_WIDTH)
	{
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

void	math_to_display(void *dis)
{
	t_game *game;
	game = dis;
	find_angle(game);
	// find_mvmnt(game->raycast);
	//move_player
	cast_rays(game);
}

