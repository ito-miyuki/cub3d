/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:11:15 by mito              #+#    #+#             */
/*   Updated: 2024/10/02 15:12:01 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	delete_texture(t_game *game, char *message)
{
	ft_putendl_fd(message, 2);
	if (game->no_texture)
		mlx_delete_texture(game->no_texture);
	if (game->so_texture)
		mlx_delete_texture(game->so_texture);
	if (game->ea_texture)
		mlx_delete_texture(game->ea_texture);
	if (game->we_texture)
		mlx_delete_texture(game->we_texture);
}

static void	free_tex_color(t_game *game)
{
	if (game->no_tex_path)
		free(game->no_tex_path);
	if (game->so_tex_path)
		free(game->so_tex_path);
	if (game->we_tex_path)
		free(game->we_tex_path);
	if (game->ea_tex_path)
		free(game->ea_tex_path);
	if (game->floor_rgb)
		free(game->floor_rgb);
	if (game->ceiling_rgb)
		free(game->ceiling_rgb);
}

void	clean_up(t_game *game)
{
	if (game->map)
		free_grid(game->map);
	free_tex_color(game);
	delete_texture(game, NULL);
	if (game->canvas)
		mlx_delete_image(game->mlx, game->canvas);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game)
		free(game);
}

void	clean_up_exit(t_game *game, char *message)
{
	if (game->file_copy)
		free_grid(game->file_copy);
	if (game->map)
		free_grid(game->map);
	free_tex_color(game);
	delete_texture(game, NULL);
	if (game->canvas)
		mlx_delete_image(game->mlx, game->canvas);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->f_split)
		free_grid(game->f_split);
	if (game->c_split)
		free_grid(game->c_split);
	if (game)
		free(game);
	if (message != NULL)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd(message, 2);
	}
	exit(1);
}
