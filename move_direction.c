/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:56:53 by alli              #+#    #+#             */
/*   Updated: 2024/09/25 12:01:10 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	for_or_back(t_game *game, char key)
{
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	if (key == 'W')
	{
		move_x = cos(game->raycast->player_angle) * PLAYER_SPEED;
		move_y = sin(game->raycast->player_angle) * PLAYER_SPEED;
	}
	if (key == 'S')
	{
		move_x = -cos(game->raycast->player_angle) * PLAYER_SPEED;
		move_y = -sin(game->raycast->player_angle) * PLAYER_SPEED;
	}
	move_player(game, move_x, move_y);
}

void	left_or_right(t_game *game, char key)
{
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	if (key == 'A')
	{
		move_x = sin(game->raycast->player_angle) * PLAYER_SPEED;
		move_y = -cos(game->raycast->player_angle) * PLAYER_SPEED;
	}
	if (key == 'D')
	{
		move_x = -sin(game->raycast->player_angle) * PLAYER_SPEED;
		move_y = cos(game->raycast->player_angle) * PLAYER_SPEED;
	}
	move_player(game, move_x, move_y);
}

void	rotate(t_game *game, char key)
{
	if (key == 'L')
	{
		game->raycast->player_angle -= ROTATE_SPEED;
		if (game->raycast->player_angle < 0)
			game->raycast->player_angle += 2 * PI;
	}
	if (key == 'R')
	{
		game->raycast->player_angle += ROTATE_SPEED;
		if (game->raycast->player_angle >= 2 * PI)
			game->raycast->player_angle -= 2 * PI;
	}
}
