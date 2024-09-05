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

int is_str_digit(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int is_color_digit(char **color_split)
{
	int i;

	i = 0;
	while (color_split[i] != NULL)
	{
		if (!is_str_digit(color_split[i]))
			return (0);
		i++;
	}
	return (1);
}

int	set_floor_colors(t_game *game, char *color_str)
{
	char **color_split;
	int rgb[3];
	int i;

	i = 0;
	color_split = ft_split(color_str, ','); // check if the str comes in a correct format
	if (!color_split)
		return (1);
	if (count_2darray_size(color_split) != 3)
	{
		// error handlings
		ft_putendl_fd("3 elements required in rgb color", 2);
		exit(1);
	}
	if (!is_color_digit(color_split))
	{
		// error handlings
		ft_putendl_fd("invalid char or format in rgb color info", 2);
		exit(1);
	}
	while (color_split[i] != NULL)
	{
		rgb[i] = ft_atol(color_split[i]); // atoi? rgb should be long?
		if (rgb[i] > 255 || rgb[i] < 0)
		{
			// error handlings
			ft_putendl_fd("avaiable color range is 0 to 255", 2);
			exit(1);
		}
		i++;
	}
	game->floor_r = rgb[0];
	game->floor_g = rgb[1];
	game->floor_b = rgb[2];
	printf("Floor Color - R: %d, G: %d, B: %d\n", game->floor_r, game->floor_g, game->floor_b);
	return (0);
}

int	set_ceiling_colors(t_game *game, char *color_str)
{
	char **color_split;
	int rgb[3];
	int i;

	i = 0;
	color_split = ft_split(color_str, ','); // check if the str comes in a correct format
	if (!color_split)
		return (1);
	if (count_2darray_size(color_split) != 3)
	{
		// error handlings
		ft_putendl_fd("3 elements required in rgb color", 2);
		exit(1);
	}
	if (!is_color_digit(color_split))
	{
		// error handlings
		ft_putendl_fd("invalid char or format in rgb color info", 2);
		exit(1);
	}
	while (color_split[i] != NULL)
	{
		rgb[i] = ft_atol(color_split[i]); // atoi? rgb should be long?
		if (rgb[i] > 255 || rgb[i] < 0)
		{
		// error handlings
			ft_putendl_fd("avaiable color range is 0 to 255", 2);
			exit(1);
		}
		i++;
	}
	game->ceiling_r = rgb[0];
	game->ceiling_g = rgb[1];
	game->ceiling_b = rgb[2];
	// dlete this printf
	printf("Ceiling Color - R: %d, G: %d, B: %d\n", game->ceiling_r, game->ceiling_g, game->ceiling_b);
	return (0);
}
