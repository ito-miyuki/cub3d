/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:11:15 by mito              #+#    #+#             */
/*   Updated: 2024/09/20 11:59:56 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


static void free_tex_color(t_game *game)
{
	if(game->no_tex_path)
	{
		printf("we game->no_tex_path in clean_up_exit()\n");
		free(game->no_tex_path);
	}
	if(game->so_tex_path)
	{
		printf("we free game->so_tex_path in clean_up_exit()\n");
		free(game->so_tex_path);
	}
	if(game->we_tex_path)
	{
		printf("we free game->we_tex_path in clean_up_exit()\n");
		free(game->we_tex_path);
	}
	if(game->ea_tex_path)
	{
		printf("we free game->ea_tex_path in clean_up_exit()\n");
		free(game->ea_tex_path);
	}
	if(game->floor_rgb)
	{
		printf("we free game->floor_rgb in clean_up_exit()\n");
		free(game->floor_rgb);
	}
	if(game->ceiling_rgb)
	{
		printf("we free game->ceiling_rgb in clean_up_exit()\n");
		free(game->ceiling_rgb);
	}
}

void	clean_up(t_game *game)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->file_copy)
	{
		printf("we free game->file_copy in clean_up_exit()\n");
		free_grid(game->file_copy);
	}
	if (game->map)
	{
		printf("we free game->map in clean_up_exit()\n");
		free_grid(game->map);
	}
	free_tex_color(game);
	if (game)
	{
		printf("we free game in clean_up_exit()\n");
		free(game);
	}
}


void	clean_up_exit(t_game *game, char *message)
{
	// if (game->mlx)
	// 	mlx_terminate(game->mlx);
	if (game->file_copy)
	{
		printf("we free game->file_copy in clean_up_exit()\n");
		free_grid(game->file_copy);
	}
	if (game->map)
	{
		printf("we free game->map in clean_up_exit()\n");
		free_grid(game->map);
	}
	free_tex_color(game);
	if (game)
	{
		printf("we free game in clean_up_exit()\n");
		free(game);
	}
	if (message != NULL)
	{
		ft_putstr_fd("Error", 2);
		if (message == NULL)
			ft_putstr_fd("\n", 2);
		else
			ft_putendl_fd(message, 2);
	}
	exit(1);
}
