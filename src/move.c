/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:09:57 by alli              #+#    #+#             */
/*   Updated: 2024/09/30 11:20:23 by alli             ###   ########.fr       */
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
	if (game->map[map_y][map_x] != '1' && game->map[map_y]
		[game->raycast->p_x / SQ_SIZE] != '1'
		&& game->map[game->raycast->p_y / SQ_SIZE][map_x] != '1')
	{
		game->raycast->p_x = new_x;
		game->raycast->p_y = new_y;
	}
}

void	move_hook(t_game *game)
{
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
