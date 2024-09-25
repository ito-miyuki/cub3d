/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:00:29 by mito              #+#    #+#             */
/*   Updated: 2024/09/23 16:47:38 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int is_map_closed_recursive(char **map, int player_y, int player_x)
{
	if (player_y < 0 || player_x < 0 || !map[player_y] || !map[player_y][player_x])
        return (0);
    if (map[player_y][player_x] == '1')
        return (1);

    map[player_y][player_x] = '1';

	if (!is_map_closed_recursive(map, player_y + 1, player_x))
		return (0);
    if (!is_map_closed_recursive(map, player_y - 1, player_x))
		return (0);
    if (!is_map_closed_recursive(map, player_y, player_x + 1))
		return (0);
    if (!is_map_closed_recursive(map, player_y, player_x - 1))
		return (0);
	return (1);
}

int is_map_closed(t_game *game, char **map)
{
	char **temp;
	int	x;
	int	y;

	x = 0;
	y = 0;
	temp = copy_2darray(map);
	if (!temp)
	{
		free_grid(temp);
		clean_up_exit(game, ": failed copy_2darray() in is map closed()");
	}
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' && is_map_closed_recursive(temp, y, x) == 0)
			{
				free_grid(temp);
				return (0);
			}
			x++;
		}
		y++;
	}
	free_grid(temp);
    return (1);
}
