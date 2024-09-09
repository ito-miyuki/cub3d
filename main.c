/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:53:20 by mito              #+#    #+#             */
/*   Updated: 2024/09/09 11:47:16 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int argc, char **argv)
{
	t_game *game;

	if (argc != 2)
		print_error_exit(": bad argument"); // think about better err msg
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		print_error_exit("Malloc failed for game struct");
	init_game(game, argv[1]);
	// for (int j = 0; game->map[j] != NULL; j++) // for testing
	// 	printf("Map line %d: %s\n", j, game->map[j]);
	// free everything
	check_colors(game->floor_rgb);
	check_colors(game->ceiling_rgb);
	get_position(game,game->map);
	mlx_loop(game->mlx);
	//mlx_loop_hook(game->mlx, &math_to_display(*dis), );
	// free(game->map);
	// free(game);
	return (0);
}
