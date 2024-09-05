/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:15:24 by alli              #+#    #+#             */
/*   Updated: 2024/09/05 15:59:00 by alli             ###   ########.fr       */
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

void	find_mvmnt(t_game *game, t_raycast *ray)
{
	double	move_x;
	double	move_y;
	
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

int wall_hit(float x, float y, t_game *game)
{
	
}

int	check_ray_dir(float angle, float *inter, float *step, int is_vert)
{
	if (!is_vert)
	{
		if (angle > 0 && angle < PI) //pointing 
		{
			*inter += SQ_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > PI / 2 && angle < 3 * PI / 2))
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
	move_ray = check_ray_dir(game->raycast->ray_angle, &y, &y_step, 1);
	x = game->player_x + (y - game->player_y) / tan(angle); //moves the ray along the x axis
	//check which way the ray is faing in the unit circle
	while (wall_hit (x, y - move_ray, game))
	{
		x += x_step;
		y += y_step;
	}
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
		h_inter = h_intersect(game, game->raycast->ray_angle);
		// v_inter = 
		//2 disstance are calculated where the ray intersects the horizontal grid line & vertical
		//keep the angle between 0-360
		//determine which one is closer
		//if v intersection is closer then set the ray distance. If the h_inter is closer then make a flag and set ddistance
		//rendder the wall (game, ray) <-for that specific ray
		//move to the next ray
	}
}

void	math_to_display(void *dis)
{
	t_game *game;
	game = dis;
	find_angle(game);
	find_mvmnt(game, game->raycast);
	//move_player
	cast_rays(game);
}