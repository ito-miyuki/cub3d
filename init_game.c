/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:21:20 by mito              #+#    #+#             */
/*   Updated: 2024/09/09 11:26:51 by alli             ###   ########.fr       */
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

static void	init_map(t_game *game, char *map_file)
{
	if (!is_extention_cub(map_file))
	{
		free(game);
		print_error_exit(": Map file must be ***.cub");
	}
	game->file_copy = create_2darray(map_file); // copy everything
	if (game->file_copy == NULL)
	{
		free(game);
		print_error_exit(": Failed to create map array");
	}
	game->info_flags = malloc(sizeof(t_flags));
	if (game->info_flags == NULL)
	{
		free_grid(game->file_copy);
		free(game);
		print_error_exit(": Failed to allocate memory for texture flags");
	}
	if (check_map_info(game->file_copy, game->info_flags) == 1) // err msg should hs more details(NO/WE is missing etc)
	{
		free_grid(game->file_copy);
		free(game->info_flags);
		free(game);
		print_error_exit(": map info is invalid");
	}
	free(game->info_flags);
	set_map_info(game, game->file_copy);
	game->map = copy_2darray(game->file_copy + 6);
	free_grid(game->file_copy);
	if (game->map == NULL)
	{
		free(game->info_flags);
		free(game);
		print_error_exit(": map info is invalid"); // is it ok to exit without freeing?
	}
	printf("\n\n"); // delet it
	for (int j = 0; game->map[j] != NULL; j++) // for testing
		printf("Map line %d: %s\n", j, game->map[j]); // for testing
	map_validation(game, game->map);
}

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

void	init_game(t_game *game, char *map_file)
{
	init_map(game, map_file); // or free everything here instead of init_map() ?
	//those below are not initialized yet
	game->height = count_2darray_size(game->map);
	game->width = get_longest(game->map);
	get_position(game, game->map);
	printf("player_x is:%zu\n", game->player_x); // delete it
	printf("player_x is:%zu\n", game->player_y); // delete it
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", false);
	if (!game->mlx)
	{
		free(game);
		print_error_exit(": mlx_init() fail"); // change it
	}
}
