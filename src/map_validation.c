/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:54:16 by mito              #+#    #+#             */
/*   Updated: 2024/10/01 15:59:24 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	has_nsew_only_once(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
		j = 0;
	}
	if (count == 1)
		return (1);
	return (0);
}

static int	has_only_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' '
				&& map[i][j] != '\t' && map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'E' && map[i][j] != 'W')
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

void	map_validation(t_game *game, char **map)
{
	game->height = 0;
	game->height = (size_t)count_2darray_size(game->map);
	if (game->height > 400 || game->width > 400)
		clean_up_exit(game, "map is too big");
	get_position(game, game->map);
	if (game->height < 3)
		clean_up_exit(game, "map is too small");
	if (!has_only_valid_chars(map))
		clean_up_exit(game, "map contains invalid char");
	if (!has_nsew_only_once(map))
		clean_up_exit(game, "map can only contain NSEW once");
	if (!is_map_closed(game, map))
		clean_up_exit(game, "map is not closed");
}
