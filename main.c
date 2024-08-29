/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:53:20 by mito              #+#    #+#             */
/*   Updated: 2024/08/29 10:43:58 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h" // delete it

int main(int argc, char **argv)
{
	t_game *game;

	if (argc != 2)
		print_error_exit(": bad argument"); // think about better err msg
	
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		print_error_exit("Malloc failed for game struct");
	init_game(game, argv[1]);
	for (int j = 0; game->map[j] != NULL; j++)
		printf("Map line %d: %s\n", j, game->map[j]);
	free(game);
	return (0);
}