/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:46:46 by mito              #+#    #+#             */
/*   Updated: 2024/09/25 13:18:30 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_str_digit(char *str)
{
	int	i;

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

static int	is_color_digit(char **color_split)
{
	int	i;

	i = 0;
	while (color_split[i] != NULL)
	{
		if (!is_str_digit(color_split[i]))
			return (0);
		i++;
	}
	return (1);
}

int	color_validation(char **color_split)
{
	if (count_2darray_size(color_split) != 3)
	{
		print_error("3 elements required in rgb color");
		return (1);
	}
	if (!is_color_digit(color_split))
	{
		print_error("invalid char or format in rgb color info");
		return (1);
	}
	return (0);
}
