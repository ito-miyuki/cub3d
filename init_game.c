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

static void set_texture_info(t_game *game, char **file_copy)
{
	char *path_start;
	int i;
	int j;
	int loop;

	i = 0;
	j = 0;
	loop = 0;
	while (loop < 6)
	{
		while (file_copy[i][j] == ' ' || file_copy[i][j] == '\t')
			j++;
		if (ft_strncmp(&file_copy[i][j], "NO", 2) == 0)
		{
			path_start = &file_copy[i][j + 2];
			while (*path_start == ' ' || *path_start == '\t')
				path_start++;
			game->no_texture = ft_strdup(path_start);
			printf("game->no_texture is:%s\n", game->no_texture);
		}
		else if (ft_strncmp(&file_copy[i][j], "SO", 2) == 0)
		{
			path_start = &file_copy[i][j + 2];
			while (*path_start == ' ' || *path_start == '\t')
				path_start++;
			game->so_texture = ft_strdup(path_start);
			printf("game->so_texture is:%s\n", game->so_texture);
		}
		else if (ft_strncmp(&file_copy[i][j], "WE", 2) == 0)
		{
			path_start = &file_copy[i][j + 2];
			while (*path_start == ' ' || *path_start == '\t')
				path_start++;
			game->we_texture = ft_strdup(path_start);
			printf("game->we_texture is:%s\n", game->we_texture);
		}
		else if (ft_strncmp(&file_copy[i][j], "EA", 2) == 0)
		{
			path_start = &file_copy[i][j + 2];
			while (*path_start == ' ' || *path_start == '\t')
				path_start++;
			game->ea_texture = ft_strdup(path_start);
			printf("game->ea_texture is:%s\n", game->ea_texture);
		}
		else if (ft_strncmp(&file_copy[i][j], "F", 1) == 0)
		{
			path_start = &file_copy[i][j + 1];
			while (*path_start == ' ' || *path_start == '\t')
				path_start++;
			game->floor_rgb = ft_strdup(path_start);
			printf("game->floor_rgb is:%s\n", game->floor_rgb);
		}
		else if (ft_strncmp(&file_copy[i][j], "C", 1) == 0)
		{
			path_start = &file_copy[i][j + 1];
			while (*path_start == ' ' || *path_start == '\t')
				path_start++;
			game->ceiling_rgb = ft_strdup(path_start);
			printf("game->ceiling_rgb is:%s\n", game->ceiling_rgb);
		}
		i++;
		j = 0;
		loop++;		
	}
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
	set_texture_info(game, game->file_copy);
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
