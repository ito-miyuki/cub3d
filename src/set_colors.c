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

static int	count_char(char *str, char c)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

static void	find_color(t_game *game, char **color_split, char c)
{
	int		rgb[3];
	int		i;

	i = -1;
	while (color_split[++i] != NULL)
	{
		rgb[i] = ft_atol(color_split[i]);
		if (rgb[i] > 255 || rgb[i] < 0)
		{
			free_grid(color_split);
			clean_up_exit(game, "available color range is 0 to 255");
		}
	}
	if (c == 'F')
	{
		game->floor_r = rgb[0];
		game->floor_g = rgb[1];
		game->floor_b = rgb[2];
	}
	else
	{
		game->ceiling_r = rgb[0];
		game->ceiling_g = rgb[1];
		game->ceiling_b = rgb[2];
	}
}

void	set_fc_colors(t_game *game, char *c_color, char *f_color)
{
	char	**c_split;
	char	**f_split;

	if (count_char(c_color, ',') != 2 || count_char(f_color, ',') != 2)
		clean_up_exit(game, "not a correct format in color info");
	c_split = ft_split(c_color, ',');
	if (!c_split)
		clean_up_exit(game, "failed to create color_split array");
	f_split = ft_split(f_color, ',');
	if (!f_split)
		clean_up_exit(game, "failed to create color_split array");
	if (color_validation(c_split) == 1 || color_validation(f_split) == 1)
	{
		free_grid(c_split);
		free_grid(f_split);
		clean_up_exit(game, NULL);
	}
	find_color(game, f_split, 'F');
	find_color(game, c_split, 'C');
	free_grid(c_split);
	free_grid(f_split);
}
