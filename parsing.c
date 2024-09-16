/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:28:37 by mito              #+#    #+#             */
/*   Updated: 2024/09/16 16:38:35 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_empty_map(char **file_copy)
{
	//printf("count_2darray_size(file_copy) is %d\n", count_2darray_size(file_copy)); // delete it

	if(file_copy[6] == NULL)
		return (1);
	return (0); // change it to free something
}

int	parsing(t_game *game, char *map_file)
{
	game->info_flags = malloc(sizeof(t_flags));
	if (game->info_flags == NULL)
		clean_up_exit(game, ": Failed to allocate memory for texture flags");
	if (check_map_info(game->file_copy, game->info_flags) == 1) // err msg should hs more details(NO/WE is missing etc)
	{
		free(game->info_flags);
		clean_up_exit(game, ": map info is invalid");
	}
	free(game->info_flags); // flags were neeeded only for check map info so free it here
	if (set_map_info(game, game->file_copy) == 1)
		clean_up_exit(game, NULL); // strdup failed is printed in set path color info func
	if (check_empty_map(game->file_copy) == 1)
		clean_up_exit(game, ": file if empty)");  // Map is empty?
	if (check_empty_line(game, map_file) == 1)
		clean_up_exit(game, NULL);
	//printf("there is no empty line in map!\n"); // delete it
	game->map = copy_2darray(game->file_copy + 6);
	if (game->map == NULL)
		clean_up_exit(game, ": failed to create game->map array");
	return (0);
}
