/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:28:37 by mito              #+#    #+#             */
/*   Updated: 2024/09/20 16:57:18 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_empty_map(char **file_copy)
{
	if(file_copy[6] == NULL)
		return (1);
	return (0); // change it to free something
}

int	parsing(t_game *game, char *map_file)
{
	game->info_flags = ft_calloc(1, sizeof(t_flags)); // is this correct?
	if (game->info_flags == NULL)
		clean_up_exit(game, ": Failed to allocate memory for texture flags");
	if (check_map_info(game->file_copy, game->info_flags) == 1) // err msg should hs more details(NO/WE is missing etc)
	{
		free(game->info_flags);
		clean_up_exit(game, ": map info is invalid");
	}
	free(game->info_flags); // flags were neeeded only for check map info so free it here
	if (set_map_info(game, game->file_copy) == 1)
		clean_up_exit(game, NULL); // "strdup" failed is printed in set path color info func
	set_floor_colors(game, game->floor_rgb); // get rgb in int
	set_ceiling_colors(game, game->ceiling_rgb);
	if (check_empty_map(game->file_copy) == 1)
		clean_up_exit(game, ": file if empty)");  // should I say Map is empty?
	if (check_empty_line(game, map_file) == 1)
		clean_up_exit(game, NULL);
	game->map = copy_2darray(game->file_copy + 6);
	if (game->map == NULL)
		clean_up_exit(game, ": failed to create game->map array");
	return (0);
}
