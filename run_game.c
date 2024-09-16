/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:16:23 by mito              #+#    #+#             */
/*   Updated: 2024/09/16 16:18:36 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static int	load_texture(t_game *game)
// {
// 	game->no_texture = mlx_load_png(game->no_tex_path);
// 	if (!game->no_texture)
// 	{
// 		ft_putendl_fd("NO texture load fail", 2);
// 		return (-1); //clean up
// 	}
// 	game->so_texture = mlx_load_png(game->so_tex_path);
// 	{
// 		ft_putendl_fd("SO texture load fail", 2);
// 		return (-1); //clean up
// 	}
// 	game->we_texture = mlx_load_png(game->we_tex_path);
// 	{
// 		ft_putendl_fd("WE texture load fail", 2);
// 		return (-1); //clean up
// 	}
// 	game->ea_texture = mlx_load_png(game->ea_tex_path);
// 	{
// 		ft_putendl_fd("EA texture load fail", 2);
// 		return (-1); //clean up
// 	}
// 	return (0);
// }

static int load_texture(t_game *game)
{
    printf("Loading textures...\n"); // delete it


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

	printf("game->so_texture is %p\n", game->so_texture);
	printf("game->no_texture is %p\n", game->no_texture);
	printf("game->we_texture is %p\n", game->we_texture);
	printf("game->ea_texture is %p\n", game->ea_texture);

    printf("All textures loaded successfully.\n");
    return (0);
}


int run_game(t_game *game) // change the function name
{
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", false);
	if (!game->mlx)
	{
		free(game);
		print_error_exit(": mlx_init() fail"); // change it
	}
	game->canvas = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->canvas)
	{
		return (-1); // do error handlings
	}
	if (mlx_image_to_window(game->mlx, game->canvas, 0, 0) == -1)
	{
		return (-1); // do error handlings
	}
	if (load_texture(game) < 0)
		return (-1);
	return (0);
}
