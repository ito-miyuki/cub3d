/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:16:23 by mito              #+#    #+#             */
/*   Updated: 2024/10/02 08:56:25 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	load_texture(t_game *game)
{
	game->no_texture = mlx_load_png(game->no_tex_path);
	if (!game->no_texture)
	{
		ft_putendl_fd("NO texture load fail", 2);
		return (-1);
	}
	game->so_texture = mlx_load_png(game->so_tex_path);
	if (!game->so_texture)
	{
		ft_putendl_fd("SO texture load fail", 2);
		return (-1);
	}
	game->we_texture = mlx_load_png(game->we_tex_path);
	if (!game->we_texture)
	{
		ft_putendl_fd("WE texture load fail", 2);
		return (-1);
	}
	game->ea_texture = mlx_load_png(game->ea_tex_path);
	if (!game->ea_texture)
	{
		ft_putendl_fd("EA texture load fail", 2);
		return (-1);
	}
	return (0);
}

void	find_angle(t_game *game)
{
	if (game->map[game->player_y][game->player_x] == 'N')
		game->raycast->player_angle = 3 * PI / 2;
	if (game->map[game->player_y][game->player_x] == 'S')
		game->raycast->player_angle = PI / 2;
	if (game->map[game->player_y][game->player_x] == 'W' )
		game->raycast->player_angle = PI;
	if (game->map[game->player_y][game->player_x] == 'E')
		game->raycast->player_angle = 0;
	game->raycast->p_x = (game->player_x * SQ_SIZE) + SQ_SIZE / 2;
	game->raycast->p_y = (game->player_y * SQ_SIZE) + SQ_SIZE / 2;
	game->raycast->player_fov = (FOV * PI / 180);
}

void	run_game(t_game *game)
{
	if (load_texture(game) < 0)
		clean_up_exit(game, ": load_texture() fail");
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", false);
	if (!game->mlx)
		clean_up_exit(game, ": mlx_init() fail");
	game->canvas = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->canvas)
		clean_up_exit(game, ": mlx_new_image() fail");
	if (mlx_image_to_window(game->mlx, game->canvas, 0, 0) == -1)
		clean_up_exit(game, ": mlx_image_to_window() fail");
}

void	math_to_display(void *data)
{
	t_game	*game;

	game = (t_game *) data;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	move_hook(game);
	cast_rays(game);
}
