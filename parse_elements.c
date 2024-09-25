/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:28:37 by mito              #+#    #+#             */
/*   Updated: 2024/09/25 14:57:48 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	**create_map(char **file_copy)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = copy_2darray(file_copy);
	if (!map)
		return (NULL);
	while (file_copy[i] != NULL)
	{
		j = 0;
		while (file_copy[i][j] != '\0')
		{
			if (file_copy[i][j] == ' ' || file_copy[i][j] == ' ')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
	return (map);
}

static int	check_empty_map(char **file_copy)
{
	if (file_copy[6] == NULL)
		return (1);
	return (0); // change it to free something
}

int	parse_elements(t_game *game, char *map_file)
{
	game->info_flags = ft_calloc(1, sizeof(t_flags)); // is this correct?
	if (game->info_flags == NULL)
		clean_up_exit(game, ": Failed to allocate memory for texture flags");
	if (check_map_info(game->file_copy, game->info_flags) == 1)
	{
		free(game->info_flags);
		clean_up_exit(game, ": map info is invalid");
	}
	free(game->info_flags);
	if (set_map_info(game, game->file_copy) == 1)
		clean_up_exit(game, NULL);
	set_floor_colors(game, game->floor_rgb);
	set_ceiling_colors(game, game->ceiling_rgb);
	if (check_empty_map(game->file_copy) == 1)
		clean_up_exit(game, ": map is empty"); // should I say Map is empty?
	if (check_empty_line(game, map_file) == 1)
		clean_up_exit(game, NULL);
	game->map = create_map(game->file_copy + 6);
	if (game->map == NULL)
		clean_up_exit(game, ": failed to create game->map array");
	return (0);
}
