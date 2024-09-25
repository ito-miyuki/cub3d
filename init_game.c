/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:21:20 by mito              #+#    #+#             */
/*   Updated: 2024/09/25 13:27:32 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static size_t	get_longest(char **map)
{
	size_t	i;
	size_t	longest;
	size_t	current;

	i = 0;
	longest = 0;
	while (map[i] != NULL)
	{
		current = ft_strlen(map[i]);
		if (current > longest)
			longest = current;
		i++;
	}
	return (longest);
}

static int	is_extention_cub(char *file_name)
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

static void	parse_file(t_game *game, char *map_file)
{
	if (!is_extention_cub(map_file)) // should this one excuted earlier than malloc game?
		clean_up_exit(game, ": Map file must be ***.cub");
	game->file_copy = create_2darray(map_file);
	if (game->file_copy == NULL)
		clean_up_exit(game, ": Failed to create map array");
	if (game->file_copy[0] == NULL)
		clean_up_exit(game, ": file is empty");
	parse_elements(game, map_file); // if it returns 1?
	free_grid(game->file_copy);
	game->file_copy = NULL;
}

void	init_game(t_game *game, char *map_file)
{
	parse_file(game, map_file); // or free everything here instead of init_map() ?
	game->width = get_longest(game->map);
	map_validation(game, game->map);
	get_position(game, game->map);
}
