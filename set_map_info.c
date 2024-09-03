/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:17:27 by mito              #+#    #+#             */
/*   Updated: 2024/09/03 11:12:20 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void set_tex_color_info(char **map_info, char *path_str)
{
    while (*path_str == ' ' || *path_str == '\t')
        path_str++;
    if (*map_info) // do I need to fo this here?
        free(*map_info);
    *map_info = ft_strdup(path_str);
    if (!*map_info)
    {
        // free every memory I allocated so far
        printf("ft_strdup failed\n");
        exit(1);
    }
    printf("Texture path is: %s\n", *map_info);
}

void    set_map_info(t_game *game, char **file_copy)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 6)
	{
		while (file_copy[i][j] == ' ' || file_copy[i][j] == '\t')
			j++;
		if (ft_strncmp(&file_copy[i][j], "NO", 2) == 0)
			set_tex_color_info(&game->no_tex_path, &file_copy[i][j + 2]);
		else if (ft_strncmp(&file_copy[i][j], "SO", 2) == 0)
			set_tex_color_info(&game->so_tex_path, &file_copy[i][j + 2]);
		else if (ft_strncmp(&file_copy[i][j], "WE", 2) == 0)
			set_tex_color_info(&game->we_tex_path, &file_copy[i][j + 2]);
		else if (ft_strncmp(&file_copy[i][j], "EA", 2) == 0)
			set_tex_color_info(&game->ea_tex_path, &file_copy[i][j + 2]);
		else if (ft_strncmp(&file_copy[i][j], "F", 1) == 0)
            set_tex_color_info(&game->floor_rgb, &file_copy[i][j + 1]);
		else if (ft_strncmp(&file_copy[i][j], "C", 1) == 0)
            set_tex_color_info(&game->ceiling_rgb, &file_copy[i][j + 1]);
		i++;
		j = 0;
	}
}
