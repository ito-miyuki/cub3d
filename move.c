/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:09:57 by alli              #+#    #+#             */
/*   Updated: 2024/09/16 09:56:02 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	for_or_back(t_game *game, char key)
{
	// if (wall_hit(game->raycast->p_x, game->raycast->p_y, game))
	// 	return ;
	printf("entered for_back\n");
	if (game->map[game->player_y - 1][game->player_x] != '1' && key == 'W')
	{
		game->player_y -= 1;
		game->raycast->p_x += cos(game->raycast->player_angle) * PLAYER_SPEED;
        game->raycast->p_y += sin(game->raycast->player_angle) * PLAYER_SPEED;
		printf("W player_y:  %zu\n", game->player_y);
		printf("W player_x:  %zu\n", game->player_x);
	}
	if (game->map[game->player_y + 1][game->player_x] != '1' && key == 'S')
	{
		game->player_y += 1;
		game->raycast->p_x -= cos(game->raycast->player_angle) * PLAYER_SPEED;
        game->raycast->p_y -= sin(game->raycast->player_angle) * PLAYER_SPEED;
		printf("S player_y:  %zu\n", game->player_y);
		printf("S player_x:  %zu\n", game->player_x);
	}
}

void	left_or_right(t_game *game, char key)
{
	// if (wall_hit(game->raycast->p_x, game->raycast->p_y, game))
	// 	return ;
	if (game->map[game->raycast->p_y][game->raycast->p_x / SQ_SIZE] != '1' && key == 'A')
	{
		game->player_x -= 1;
		// game->raycast->p_x = game->player_x * SQ_SIZE
		game->raycast->p_x += cos(game->raycast->player_angle - PI / 2) * PLAYER_SPEED;
        game->raycast->p_y += sin(game->raycast->player_angle - PI / 2) * PLAYER_SPEED;
		// printf("A player_y:  %zu\n", game->player_y);
		// printf("A player_x:  %zu\n", game->player_x);
	}
	if (game->map[game->player_y][game->player_x + 1] != '1' && key == 'D')
	{
		game->player_x += 1;
		game->raycast->p_x += cos(game->raycast->player_angle + PI / 2) * PLAYER_SPEED;
        game->raycast->p_y += sin(game->raycast->player_angle + PI / 2) * PLAYER_SPEED;
		// printf("D player_y:  %zu\n", game->player_y);
		// printf("D player_x:  %zu\n", game->player_x);
	}
}
void	rotate(t_game *game, char key)
{
	// printf("before player_angle in rotate: %f\n", game->raycast->player_angle);
	if (key == 'L')
	{
		game->raycast->player_angle -= ROTATE_SPEED;
		if (game->raycast->player_angle < 0)
			game->raycast->player_angle += 2 * PI;
		// game->raycast->p_x = cos(game->raycast->player_angle) * PLAYER_SPEED;
		// game->raycast->p_y = sin(game->raycast->player_angle) * PLAYER_SPEED;
	}
	if (key == 'R')
	{
		game->raycast->player_angle += ROTATE_SPEED;
		if (game->raycast->player_angle > 2 * PI)
			game->raycast->player_angle -= 2 * PI;
		// game->raycast->p_x = cos(game->raycast->player_angle) * PLAYER_SPEED;
		// game->raycast->p_y = sin(game->raycast->player_angle) * PLAYER_SPEED;
	}
	// game->raycast->p_x = cos(game->raycast->player_angle) * PLAYER_SPEED;
	// game->raycast->p_y = sin(game->raycast->player_angle) * PLAYER_SPEED;
	// printf("after player_angle in rotate: %f\n", game->raycast->player_angle);
}

void	move_hook(void *data)
{
	t_game *game;
	
	game = (t_game *)data;
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
	cast_rays(game);
}