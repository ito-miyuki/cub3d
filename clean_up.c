/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:11:15 by mito              #+#    #+#             */
/*   Updated: 2024/09/13 11:51:24 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//from so long
// void	clean_up(t_game *game, char *message)
// {
// 	if (game->mlx)
// 		mlx_close_window(game->mlx);
// 	if (game->grid)
// 		free_grid(game->grid);
// 	if (game->img)
// 		free(game->img);
// 	if (message != NULL)
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		ft_putendl_fd(message, 2);
// 	}
// }

void	clean_up_exit(t_game *game, char *message)
{
	// if (game->mlx)
	// 	mlx_terminate(game->mlx);
	if (game->file_copy)
		free_grid(game->file_copy);
	if (game->map)
		free_grid(game->map);
	// if (game->img)
	// 	free(game->img);
	if (game)
		free(game);
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
