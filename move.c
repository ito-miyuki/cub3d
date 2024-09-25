/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:09:57 by alli              #+#    #+#             */
/*   Updated: 2024/09/25 11:04:05 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	move_player(t_game *game, double move_x, double move_y)
{
	double	new_x;
	double	new_y;
	int		map_x;
	int		map_y;

	new_x = game->raycast->p_x + move_x;
	new_y = game->raycast->p_y + move_y;
	map_x = new_x / SQ_SIZE;
	map_y = new_y / SQ_SIZE;
	if (game->map[map_y][map_x] != '1' && game->map[map_y][game->raycast->p_x / SQ_SIZE] != '1'
		&& game->map[game->raycast->p_y / SQ_SIZE][map_x] != '1')
	{
		game->raycast->p_x = new_x;
		game->raycast->p_y = new_y;
	}
}

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

void	move_hook(t_game *game)
{
	// t_game	*game;
	
	// game = (t_game *)data;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		for_or_back(game, 'W');
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		for_or_back(game, 'S');
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		left_or_right(game, 'A');
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		left_or_right(game, 'D');
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate(game, 'L');
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate(game, 'R');
}
void	mouse_movement(double xpos, double ypos, void *data)
{
	t_game *game = data;
	static double old_pos;
	
	(void)ypos;
	if (xpos <= old_pos)
		rotate(game, 'L');
	else 
		rotate(game, 'R');
	old_pos = xpos;
}