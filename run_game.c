/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:16:23 by mito              #+#    #+#             */
/*   Updated: 2024/09/18 10:43:30 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*static void	paint_floor_ceiling(t_game *game)
{
	uint32_t x;
	uint32_t y;

	x = 0;
	y = 0;
    while (y < WINDOW_HEIGHT / 2)
    {
        x = 0;
        while (x < WINDOW_WIDTH)
        {
            mlx_put_pixel(game->canvas, x, y,
				color(game->ceiling_r, game->ceiling_g, game->ceiling_b));
			x++;
        }
        y++;
    }
	printf("ceiling color is: r %d g %d b %d\n", game->ceiling_r, game->ceiling_g, game->ceiling_b);
	while (y < WINDOW_HEIGHT)
    {
        x = 0;
        while (x < WINDOW_WIDTH)
        {
            mlx_put_pixel(game->canvas, x, y,
				color(game->floor_r, game->floor_g, game->floor_b));
            x++;
        }
        y++;
    }
	printf("floor color is: r %d g %d b %d\n", game->floor_r, game->floor_g, game->floor_b);
}*/

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
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", false);
	if (!game->mlx)
	{
		free(game);
		print_error_exit(": mlx_init() fail"); // change it
	}
	game->canvas = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->canvas)
	{
		ft_putendl_fd("canvas is NULL", 2);
		return (-1);
	}
	// paint_floor_ceiling(game);
	if (!mlx_image_to_window(game->mlx, game->canvas, 0, 0))
		return (-1);
	if (load_texture(game) == -1)
		return (-1);
	return (0);
}
