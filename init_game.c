/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:21:20 by mito              #+#    #+#             */
/*   Updated: 2024/09/18 12:11:28 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static size_t    get_longest(char **map)
{
	size_t i;
	size_t longest;
	size_t current;

	i = 0;
	longest = 0;
	while(map[i] != NULL)
	{
		current = ft_strlen(map[i]);
		if (current > longest)
			longest = current;
		i++;
	}
	return (longest);
}

static int is_extention_cub(char *file_name)
{
	int		len;
	char	*format;

	len = ft_strlen(file_name);
	format = ".cub";
	if (len < 4)
		return (0);
	if (len == 4)
		return (0);
	len = ft_strlen(file_name) - 4;
	if (file_name[len - 1] == '/')
		return (0);
	if (ft_strncmp(&file_name[len], format, 4) != 0)
		return (0);
	return (1);
}

static void	init_map(t_game *game, char *map_file)
{
	if (!is_extention_cub(map_file))
		clean_up_exit(game, ": Map file must be ***.cub");
	game->file_copy = create_2darray(map_file); // copy everything without empty lines
	if (game->file_copy == NULL)
		clean_up_exit(game, ": Failed to create map array");
	if (game->file_copy[0] == NULL) // if the file is empty. it also when the file only has empty lines
		clean_up_exit(game, ": file is empty");
	parsing(game, map_file); // if it returns 1?
	free_grid(game->file_copy);
	map_validation(game, game->map);
}

void	init_game(t_game *game, char *map_file)
{
	init_map(game, map_file); // or free everything here instead of init_map() ?
	//those below are not initialized yet
	game->width = get_longest(game->map);
	get_position(game, game->map);
}
