/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:21:20 by mito              #+#    #+#             */
/*   Updated: 2024/08/28 11:26:32 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

// static map_content_validation(char *map)
// {
// 	int	fd;

// 	fd = open(map, O_RDONLY);
// 	if (fd == -1)
// 		print_error_exit(": open() failed"); // is it good err message?


// }

// // is void good? Think again
// void map_validation(char *map)
// {
// 	if (!is_extention_cub(map))
// 		print_error_exit(": Map file must be ***.cub");
// 	map_content_validation(map);
// 	/*
// 		is_closed() by wall

// 	*/
// 	ft_putstr_fd("map is valid\n", 1); // delete it
// }


// this is from so_long
t_map *init_map(char *map)
{
	char	*map_str;
	char	**map_array;
	t_map	*map;

	if (!is_extention_cub(map)) // check if the file is .cub
		print_error_exit(": Map file must be ***.cub"); // is it ok to exit without freeing?
	map_str = read_map(map); // remove empty line from here
	if (map_str == NULL)
		exit(EXIT_FAILURE); // change it
	map_array = ft_split(map_str, '\n');
	if (!map_array)
	{
		free(map_str); // think again about freeing things
		print_error_exit(": malloc failed");
	}
	// do map valdation here
	map = init_map_struct(map_str, map_array);
	// if (ft_flood_fill(data) == false)
	// {
	// 	free(map_str);
	// 	clean_up_exit(data, "Invalid path");
	// }
	free(map_str);
	return (map);
}
