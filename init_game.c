/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:21:20 by mito              #+#    #+#             */
/*   Updated: 2024/08/30 16:42:59 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
// 	map_content_validation(map);
// 	/*
// 		is_closed() by wall

// 	*/
// 	ft_putstr_fd("map is valid\n", 1); // delete it
// }


static void	init_map(t_game *game, char *map_file)
{
	if (!is_extention_cub(map_file))
		print_error_exit(": Map file must be ***.cub"); // is it ok to exit without freeing?
	game->file_copy = create_2darray(map_file);
	if (game->file_copy == NULL)
		print_error_exit(": Failed to create map array"); // is it ok to exit without freeing?

	game->info_flags = malloc(sizeof(t_flags));
	if (game->info_flags == NULL)
	{
		free_grid(game->file_copy);
		print_error_exit(": Failed to allocate memory for texture flags");
	}
	if (check_map_info(game->file_copy, game->info_flags) == 1) // err msg should hs more details(NO/WE is missing etc)
	{
		free_grid(game->file_copy);
		print_error_exit(": map info is invalid"); // is it ok to exit without freeing?
	}
	set_map_info(game, game->file_copy);
	game->map = copy_2darray(game->file_copy + 6);
	free_grid(game->file_copy);
	printf("\n\n"); // delet it
	for (int j = 0; game->map[j] != NULL; j++) // for testing
		printf("Map line %d: %s\n", j, game->map[j]); // for testing

	// do map valdation here
	// if (ft_flood_fill(data) == false)
	// {
		// 	free(map_str);
		// 	clean_up_exit(data, "Invalid path");
	// }
}

void	init_game(t_game *game, char *map_file)
{
	init_map(game, map_file);
}
