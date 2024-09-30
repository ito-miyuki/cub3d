/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:53:20 by mito              #+#    #+#             */
/*   Updated: 2024/09/30 10:47:54 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3D_bonus.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		print_error_exit(": not correct argc");
	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		print_error_exit(": Malloc failed for game struct");
	init_game(game, argv[1]);
	run_game(game);
	game->raycast = malloc(sizeof(t_raycast));
	if (!game->raycast)
		clean_up_exit(game, "Malloc failed for raycast struct");
	find_angle(game);
	mlx_loop_hook(game->mlx, math_to_display, game);
	mlx_cursor_hook(game->mlx, &mouse_movement, game);
	mlx_loop(game->mlx);
	free(game->raycast);
	clean_up(game);
	return (0);
}
