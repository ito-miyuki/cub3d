/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:16:23 by mito              #+#    #+#             */
/*   Updated: 2024/09/25 11:12:30 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	delete_texture(t_game *game)
{
	if (game->no_texture)
		mlx_delete_texture(game->no_texture);
	if (game->so_texture)
		mlx_delete_texture(game->so_texture);
	if (game->ea_texture)
		mlx_delete_texture(game->ea_texture);
	if (game->we_texture)
		mlx_delete_texture(game->we_texture);
}

static int load_texture(t_game *game)
{
	game->no_texture = mlx_load_png(game->no_tex_path);
	if (!game->no_texture)
	{
		ft_putendl_fd("NO texture load fail\n", 2);
		return (-1);
	}
	game->so_texture = mlx_load_png(game->so_tex_path);
	if (!game->so_texture)
	{
		ft_putendl_fd("SO texture load fail\n", 2);
		delete_texture(game);
		return (-1);
	}
	game->we_texture = mlx_load_png(game->we_tex_path);
	if (!game->we_texture)
	{
		ft_putendl_fd("WE texture load fail\n", 2);
		delete_texture(game);
		return (-1);
	}
	game->ea_texture = mlx_load_png(game->ea_tex_path);
	if (!game->ea_texture)
	{
		ft_putendl_fd("EA texture load fail\n", 2);
		delete_texture(game);
		return (-1);
	}
	return (0);
}

void	find_angle(t_game *game)
{
	if (game->map[game->player_y][game->player_x]  == 'N')
		game->raycast->player_angle = NORTH;
	if (game->map[game->player_y][game->player_x] == 'S')
		game->raycast->player_angle = SOUTH;
	if (game->map[game->player_y][game->player_x] == 'W' )
		game->raycast->player_angle = WEST;
	if (game->map[game->player_y][game->player_x] == 'E')
		game->raycast->player_angle = EAST;
	game->raycast->p_x = (game->player_x * SQ_SIZE) + SQ_SIZE / 2;
	game->raycast->p_y = (game->player_y * SQ_SIZE) + SQ_SIZE / 2;
	game->raycast->player_fov = (FOV * PI / 180);
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

void	math_to_display(void *data)
{
	t_game *game;

	game = (t_game *) data;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	move_hook(game);
	cast_rays(game);
}
