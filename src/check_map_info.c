/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:48:21 by mito              #+#    #+#             */
/*   Updated: 2024/10/01 16:45:34 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	print_missing_flags(t_flags *flags)
{
	if (flags->all_flags == 0)
	{
		ft_putendl_fd("all map info is missing or placed in a wrong place", 2);
		return ;
	}
	if (flags->no == 0)
		ft_putendl_fd("Please put NO correctly", 2);
	if (flags->so == 0)
		ft_putendl_fd("Please put SO correctly", 2);
	if (flags->we == 0)
		ft_putendl_fd("Please put WE correctly", 2);
	if (flags->ea == 0)
		ft_putendl_fd("Please put EA correctly", 2);
	if (flags->f == 0)
		ft_putendl_fd("Please put F correctly", 2);
	if (flags->c == 0)
		ft_putendl_fd("Please put C correctly", 2);
}

static void	init_flags(t_flags *flags)
{
	flags->no = 0;
	flags->so = 0;
	flags->we = 0;
	flags->ea = 0;
	flags->f = 0;
	flags->c = 0;
	flags->all_flags = 0;
}

static int	check_duplicate(char **file_copy, t_flags *flags)
{
	while (*file_copy != NULL)
	{
		if (set_flags(*file_copy, flags) == 1)
			return (1);
		file_copy++;
	}
	return (0);
}

static int	check_elements(char **file_copy, t_flags *flags)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (file_copy[i] != NULL && count < 6)
	{
		if (is_all_space(file_copy[i]))
		{
			i++;
			continue ;
		}
		else if (set_flags(file_copy[i], flags) == 1)
			return (-1);
		else
		{
			i++;
			count++;
		}
	}
	return (i);
}

int	check_map_info(char **file_copy, t_game *game, t_flags *flags)
{
	int	last_item;

	init_flags(flags);
	last_item = check_elements(file_copy, flags);
	if (last_item < 0)
		return (1);
	if (flags->all_flags != 6)
	{
		print_missing_flags(flags);
		return (1);
	}
	game->last_item = last_item - 1;
	if (check_duplicate(&file_copy[last_item], flags) == 1)
		return (1);
	return (0);
}
