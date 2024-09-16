/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:16:23 by mito              #+#    #+#             */
/*   Updated: 2024/09/16 16:48:51 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int load_texture(t_game *game)
{
    game->no_texture = mlx_load_png(game->no_tex_path);
    if (!game->no_texture)
    {
        printf("NO texture load fail\n");
        return (-1);
    }
    game->so_texture = mlx_load_png(game->so_tex_path);
    if (!game->so_texture)
    {
        printf("SO texture load fail\n");
        mlx_delete_texture(game->no_texture);
        return (-1);
    }
    game->we_texture = mlx_load_png(game->we_tex_path);
    if (!game->we_texture)
    {
        printf("WE texture load fail\n");
        mlx_delete_texture(game->no_texture);
        mlx_delete_texture(game->so_texture);
        return (-1);
	}
    game->ea_texture = mlx_load_png(game->ea_tex_path);
    if (!game->ea_texture)
    {
        printf("EA texture load fail\n");
        mlx_delete_texture(game->no_texture);
        mlx_delete_texture(game->so_texture);
        mlx_delete_texture(game->we_texture);
        return (-1);
    }
    return (0);
}


int run_game(t_game *game) // change the function name
{
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", false);
	if (!game->mlx)
		clean_up_exit(game, ": mlx_init() fail");
	game->canvas = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->canvas)
		clean_up_exit(game, ": mlx_new_image() fail");
	if (mlx_image_to_window(game->mlx, game->canvas, 0, 0) == -1)
		clean_up_exit(game, ": mlx_image_to_window() fail");
	if (load_texture(game) < 0)
		clean_up_exit(game, ": load_texture() fail");
	return (0);
}
