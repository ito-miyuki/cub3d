/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:27:23 by mito              #+#    #+#             */
/*   Updated: 2024/08/28 11:32:16 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*init_map_struct(char *map_str, char **map_array)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		free(map_str);
		free_grid(map_array);
		print_error_exit(": calloc failed");
	}
	map->grid = map_array;
	map->width = ft_strlen(map_array[0]);
	map->height = row_count(map_array);
	map->player_x = get_position(map, 'P', 'x');
	map->player_y = get_position(map, 'P', 'y');
	return (map);
}
