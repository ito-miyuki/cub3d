/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:15:24 by alli              #+#    #+#             */
/*   Updated: 2024/09/04 15:36:29 by alli             ###   ########.fr       */
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

void	cast_rays(t_game *game)
{
	double	h_inter;
	double	v_inter;

	
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