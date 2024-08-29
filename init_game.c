/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:21:20 by mito              #+#    #+#             */
/*   Updated: 2024/08/29 12:14:27 by mito             ###   ########.fr       */
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


// int is_nswe(char *map_file)
// {

// }

// this is from so_long


static t_game *init_map(t_game *game, char *map_file)
{
	char	*map_str;
	char	**map_array;
	t_game	*map;

	if (!is_extention_cub(map_file)) // check if the file is .cub
		print_error_exit(": Map file must be ***.cub"); // is it ok to exit without freeing?
	if (duplicate_file() == NULL)
		print_error_exit(": Map file must be ***.cub"); // is it ok to exit without freeing?
	// do check with NSWE
	// do map valdation here
	// if (ft_flood_fill(data) == false)
	// {
	// 	free(map_str);
	// 	clean_up_exit(data, "Invalid path");
	// }
	free(map_str);
	return (map);
}

t_game *init_game(t_game *game, char *map)
{
	game->map = init_map(game, map);
}
