/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:37:15 by mito              #+#    #+#             */
/*   Updated: 2024/09/03 16:31:42 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_colors(char *color_str)
{
	char **color_split;
	int rgb[3];
	int i;

	i = 0;
	color_split = ft_split(color_str, ','); // check if the str comes in a correct format
	if (!color_split)
		return (1);
	while (color_split[i] != NULL)
	{
		rgb[i] = atoi(*color_split);
		if (rgb[i] > 255 || rgb[i] < 0)
			return (1);
		printf("test: is:%d\n", rgb[i]);
		i++;
	}
	color(rgb[0],rgb[1], rgb[2], 100); // change the last one!!!
	return (0);
}
