/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:17:27 by mito              #+#    #+#             */
/*   Updated: 2024/10/02 08:29:41 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	set_path_color_info(char **map_info, char *path_str)
{
	if (*map_info)
		free(*map_info);
	*map_info = ft_strtrim(path_str, " ");
	if (!*map_info)
	{
		print_error("ft_strtrim() failed in set_path_color_info");
		return (1);
	}
	return (0);
}

static int	set_dir_path(t_game *game, char *direction)
{
	if (ft_strncmp(direction, "NO", 2) == 0)
	{
		if (set_path_color_info(&game->no_tex_path, (direction + 2)) != 0)
			return (1);
	}
	else if (ft_strncmp(direction, "SO", 2) == 0)
	{
		if (set_path_color_info(&game->so_tex_path, (direction + 2)) != 0)
			return (1);
	}
	else if (ft_strncmp(direction, "WE", 2) == 0)
	{
		if (set_path_color_info(&game->we_tex_path, (direction + 2)) != 0)
			return (1);
	}
	else if (ft_strncmp(direction, "EA", 2) == 0)
	{
		if (set_path_color_info(&game->ea_tex_path, (direction + 2)) != 0)
			return (1);
	}
	return (0);
}

static int	set_color_info(t_game *game, char *color_info)
{
	if (ft_strncmp(color_info, "F", 1) == 0)
	{
		if (set_path_color_info(&game->floor_rgb, (color_info + 1)) != 0)
			return (1);
	}
	else if (ft_strncmp(color_info, "C", 1) == 0)
	{
		if (set_path_color_info(&game->ceiling_rgb, (color_info + 1)) != 0)
			return (1);
	}
	return (0);
}

int	set_map_info(t_game *game, char **file_copy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (game->last_item + 1))
	{
		while (file_copy[i][j] == ' ' || file_copy[i][j] == '\t')
			j++;
		if (ft_strncmp(&file_copy[i][j], "C", 1) != 0
			&& ft_strncmp(&file_copy[i][j], "F", 1) != 0)
		{
			if (set_dir_path(game, &file_copy[i][j]) == 1)
				return (1);
		}
		else
		{
			if (set_color_info(game, &file_copy[i][j]) == 1)
				return (1);
		}
		i++;
		j = 0;
	}
	return (0);
}
