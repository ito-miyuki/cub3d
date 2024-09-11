/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:09:57 by alli              #+#    #+#             */
/*   Updated: 2024/09/11 15:50:09 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	for_or_back(t_game *game, char key)
{
	// if (wall_hit(game->raycast->p_x, game->raycast->p_y, game))
	// 	return ;
	if (game->map[game->player_y - 1][game->player_x] != '1' && key == 'W')
	{
		game->player_y -= 1;
	}
	if (game->map[game->player_y + 1][game->player_x] != '1' && key == 'S')
	{
		game->player_y += 1;
	}
}

void	left_or_right(t_game *game, char key)
{
	// if (wall_hit(game->raycast->p_x, game->raycast->p_y, game))
	// 	return ;
	if (game->map[game->player_y][game->player_x - 1] != '1' && key == 'A')
	{
		game->player_x -= 1;
	}
	if (game->map[game->player_y][game->player_x + 1] != '1' && key == 'D')
	{
		game->player_x +=1;
	}
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
	cast_rays(game);
	// if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	// 	//rotate left
	// if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	// 	//rotate right
}