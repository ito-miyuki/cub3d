/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:37:15 by mito              #+#    #+#             */
/*   Updated: 2024/09/05 10:03:03 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int count_char(char *str, char c)
{
	int count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

void	set_floor_colors(t_game *game, char *color_str)
{
	char **color_split;
	//uint32_t rgb[3];
	int rgb[3];
	int i;

	i = 0;
	if (count_char(color_str, ',') != 2)
		clean_up_exit(game, ": not a correct format in color info");
	color_split = ft_split(color_str, ',');
	if (!color_split)
		clean_up_exit(game, ": failed to create color_split array");
	if (color_validation(color_split) == 1)
	{
		free_grid(color_split);
		clean_up_exit(game, NULL);
	}
	while (color_split[i] != NULL)
	{
		rgb[i] = ft_atoi(color_split[i]); // atol? rgb should be long?
		if (rgb[i] > 255 || rgb[i] < 0)
		{
			free_grid(color_split);
			clean_up_exit(game, ": avaiable color range is 0 to 255");
		}
		i++;
	}
	game->floor_r = rgb[0];
	game->floor_g = rgb[1];
	game->floor_b = rgb[2];
	free_grid(color_split);
}

void	set_ceiling_colors(t_game *game, char *color_str)
{
	char **color_split;
	//uint32_t rgb[3];
	int rgb[3];
	int i;

	i = 0;
	if (count_char(color_str, ',') != 2)
		clean_up_exit(game, ": not a correct format in color info");
	color_split = ft_split(color_str, ',');
	if (!color_split)
		clean_up_exit(game, ": failed to create color_split array");
	if (color_validation(color_split) == 1)
	{
		free_grid(color_split);
		clean_up_exit(game, NULL);
	}
	while (color_split[i] != NULL)
	{
		rgb[i] = ft_atoi(color_split[i]); // atoi? rgb should be long?
		if (rgb[i] > 255 || rgb[i] < 0)
		{
			free_grid(color_split);
			clean_up_exit(game, ": avaiable color range is 0 to 255");
		}
		i++;
	}
	game->ceiling_r = rgb[0];
	game->ceiling_g = rgb[1];
	game->ceiling_b = rgb[2];
	free_grid(color_split);
}
