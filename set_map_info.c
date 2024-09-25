/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:17:27 by mito              #+#    #+#             */
/*   Updated: 2024/09/25 17:10:49 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int set_path_color_info(char **map_info, char *path_str)
{
    while (*path_str == ' ' || *path_str == '\t')
        path_str++;
    if (*map_info) // do I need to fo this here?
        free(*map_info);
    *map_info = ft_strtrim(path_str, " ");
	//*map_info = ft_strdup(path_str);
    if (!*map_info)
    {
        ft_putendl_fd("ft_strdup() failed in set_path_color_info", 2);
        return(1);
    }
    return (0);
}

int	set_map_info(t_game *game, char **file_copy) // this is for saving the path to the struct
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 6)
	{
		printf("file_copy[i] is '%s'\n", file_copy[i]);
		while (file_copy[i][j] == ' ' || file_copy[i][j] == '\t')
			j++;
		if (ft_strncmp(&file_copy[i][j], "NO", 2) == 0)
		{
            if (set_path_color_info(&game->no_tex_path, &file_copy[i][j + 2]) != 0)
				return (1); // strdup failed is printed in set path color info func
        }
		else if (ft_strncmp(&file_copy[i][j], "SO", 2) == 0)
		{
            if (set_path_color_info(&game->so_tex_path, &file_copy[i][j + 2]) != 0)
				return (1);
        }
		else if (ft_strncmp(&file_copy[i][j], "WE", 2) == 0)
        {
            if (set_path_color_info(&game->we_tex_path, &file_copy[i][j + 2]) != 0)
				return (1);
        }
		else if (ft_strncmp(&file_copy[i][j], "EA", 2) == 0)
        {
            if (set_path_color_info(&game->ea_tex_path, &file_copy[i][j + 2]) != 0)
				return (1);
        }
		else if (ft_strncmp(&file_copy[i][j], "F", 1) == 0)
        {
            if (set_path_color_info(&game->floor_rgb, &file_copy[i][j + 1]) != 0)
				return (1);
        }
		else if (ft_strncmp(&file_copy[i][j], "C", 1) == 0)
        {
            if (set_path_color_info(&game->ceiling_rgb, &file_copy[i][j + 1]) != 0)
				return (1);
        }
		printf("game->no_tex_path is '%s'\n", game->no_tex_path);
		i++;
		j = 0;
	}
	return (0);
}
