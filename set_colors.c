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

// static int check_format(char **color)
// {
// 	int i;

// 	i = 0;
// 	while (color[i] != NULL)
// 	{
// 		if (ft_strlen(color[i]) != 3 ||
// 			!ft_isdigit(color[i][0]) || is_space(color[i][0]))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

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
int is_str_digit(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
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
	//uint32_t rgb[3];
	int rgb[3];
	int i;

	i = 0;
	if (count_char(color_str, ',') != 2)
		clean_up_exit(game, ": not a correct format in color info");
	color_split = ft_split(color_str, ','); // add checks if the str comes in a correct format
	if (!color_split)
		return (1); // do something else
	if (count_2darray_size(color_split) != 3)
	{
		free_grid(color_split);
		clean_up_exit(game, ": 3 elements required in rgb color");
	}
	// if (!is_color_digit(color_split) || check_format(color_split) == 1)
	// {
	// 	free_grid(color_split);
	// 	clean_up_exit(game, ": invalid char or format in rgb color info");
	// }
	while (color_split[i] != NULL)
	{
		rgb[i] = ft_atoi(color_split[i]); // atol? rgb should be long?
		printf("rgb[%d] is %d\n",i,rgb[i]); // delete it
		if (rgb[i] > 255 || rgb[i] < 0)
		{
			free_grid(color_split);
			clean_up_exit(game, "avaiable color range is 0 to 255");
		}
		i++;
	}
	game->floor_r = rgb[0];
	game->floor_g = rgb[1];
	game->floor_b = rgb[2];
	free_grid(color_split);
	return (0);
}

int	set_ceiling_colors(t_game *game, char *color_str)
{
	char **color_split;
	//uint32_t rgb[3];
	int rgb[3];
	int i;

	i = 0;
	if (count_char(color_str, ',') != 2)
		clean_up_exit(game, ": not a correct format in color info");
	color_split = ft_split(color_str, ','); // check if the str comes in a correct format
	if (!color_split)
		return (1);
	for (int i = 0; color_split[i] != NULL; i++) // delete it
		printf("splited str is '%s'\n", color_split[i]); // delete it
	if (count_2darray_size(color_split) != 3)
	{
		free_grid(color_split);
		clean_up_exit(game, "3 elements required in rgb color");
	}
	if (!is_color_digit(color_split))
	{
		free_grid(color_split);
		clean_up_exit(game, "invalid char or format in rgb color info");
	}
	while (color_split[i] != NULL)
	{
		rgb[i] = ft_atoi(color_split[i]); // atoi? rgb should be long?
		printf("rgb[%d] is %d\n",i,rgb[i]);
		if (rgb[i] > 255 || rgb[i] < 0)
		{
			free_grid(color_split);
			clean_up_exit(game, "avaiable color range is 0 to 255");
		}
		i++;
	}
	game->ceiling_r = rgb[0];
	game->ceiling_g = rgb[1];
	game->ceiling_b = rgb[2];
	free_grid(color_split);
	return (0);
}
