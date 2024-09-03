/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:16:23 by mito              #+#    #+#             */
/*   Updated: 2024/09/03 11:41:19 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	load_texture(t_game *game)
{
	game->no_texture = mlx_load_png(game->no_tex_path);
	if (!game->no_texture)
	{
		ft_putendl_fd("NO texture load fail", 2);
		return (-1); //clean up
	}
	game->so_texture = mlx_load_png(game->so_tex_path);
	{
		ft_putendl_fd("SO texture load fail", 2);
		return (-1); //clean up
	}
	game->we_texture = mlx_load_png(game->we_tex_path);
	{
		ft_putendl_fd("WE texture load fail", 2);
		return (-1); //clean up
	}
	game->ea_texture = mlx_load_png(game->ea_tex_path);
	{
		ft_putendl_fd("EA texture load fail", 2);
		return (-1); //clean up
	}
	return (0);
}

int run_game(t_game *game) // change the function name
{
	game->canvas = mlx_new_image(game->mlx, 128, 128);
	if (game->canvas == 0)
		return (-1);
	if (!mlx_image_to_window(game->mlx, game->canvas, 0, 0))
		return (-1);
	return (0);
	if (load_texture(game) == -1)
		return (-1);
}
