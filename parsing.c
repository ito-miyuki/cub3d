/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:28:37 by mito              #+#    #+#             */
/*   Updated: 2024/09/12 15:20:24 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_empty_map(char **file_copy)
{
	printf("count_2darray_size(file_copy) is %d\n", count_2darray_size(file_copy)); // delete it

	if(file_copy[6] == NULL)
		printf("no map in a file\n"); // change it to free something
	exit(1); // change it to free something
}

int	parsing(t_game *game)
{
	game->info_flags = malloc(sizeof(t_flags));
	if (game->info_flags == NULL)
	{
		free_grid(game->file_copy);
		free(game);
		print_error_exit(": Failed to allocate memory for texture flags");
	}
	if (check_map_info(game->file_copy, game->info_flags) == 1) // err msg should hs more details(NO/WE is missing etc)
	{
		free_grid(game->file_copy);
		free(game->info_flags);
		free(game);
		print_error_exit(": map info is invalid");
	}
	free(game->info_flags);
	set_map_info(game, game->file_copy);
	check_empty_map(game->file_copy);
	check_empty_line(game, game->filename);
	printf("there is no empty line in map!\n"); // delete it
	game->map = copy_2darray(game->file_copy + 6);
	free_grid(game->file_copy);
	if (game->map == NULL)
	{
		free(game->info_flags);
		free(game);
		print_error_exit(": map info is invalid"); // is it ok to exit without freeing?
	}
	map_validation(game, game->map);
	return (0);
}
