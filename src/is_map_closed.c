/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:00:29 by mito              #+#    #+#             */
/*   Updated: 2024/09/27 10:22:12 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_map_closed_recursive(char **map, int player_y, int player_x)
{
	if (player_y < 0 || player_x < 0
		|| !map[player_y] || !map[player_y][player_x])
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

static int	floodfill_map(char **map, char **char_temp)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
				&& is_map_closed_recursive(char_temp, y, x) == 0)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

// static int	only_char(char *str, char c)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] != c)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// static	int	check_wall_rows(char **map)
// {
// 	int	last_row;

// 	last_row = count_2darray_size(map);
// 	if (!(only_char(map[0], '1')))
// 		return (1);
// 	if (!(only_char(map[last_row - 1], '1')))
// 		return (1);
// 	return (0);
// }

// static int	check_wall_columns(char **map_array)
// {
// 	int	i;
// 	int	last_idx;

// 	i = 0;
// 	last_idx = ft_strlen(map_array[0]) - 1;
// 	while (map_array[i] != NULL)
// 	{
// 		if ((map_array[i][0] == 'N') || (map_array[i][0] == 'S') || (map_array[i][0] == 'W') || (map_array[i][0] == 'E')
// 		|| (map_array[i][last_idx] == 'N') || (map_array[i][last_idx] == 'S') || (map_array[i][last_idx] == 'W') || (map_array[i][last_idx] == 'E'))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// static int	is_player_onedge(char **map)
// {
// 	if (check_wall_columns(map) == 1 || check_wall_rows(map) == 1)
// 		return (1);
// 	return (0);
// }

int	is_map_closed(t_game *game, char **map)
{
	char	**temp;

	// if (is_player_onedge(map) == 1)
	// 	return (0);
	temp = copy_2darray(map);
	if (!temp)
	{
		free_grid(temp);
		clean_up_exit(game, "failed copy_2darray() in is map closed()");
	}
	if (floodfill_map(map, temp) == 1)
	{
		free_grid(temp);
		return (0);
	}
	free_grid(temp);
	return (1);
}
