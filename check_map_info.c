/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:48:21 by mito              #+#    #+#             */
/*   Updated: 2024/09/26 14:32:06 by mito             ###   ########.fr       */
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
		ft_putendl_fd("Please put NO in a correct format/position", 2);
	if (flags->so == 0)
		ft_putendl_fd("Please put SO in a correct format/position", 2);
	if (flags->we == 0)
		ft_putendl_fd("Please put WE in a correct format/position", 2);
	if (flags->ea == 0)
		ft_putendl_fd("Please put EA in a correct format/position", 2);
	if (flags->f == 0)
		ft_putendl_fd("Please put F in a correct format/position", 2);
	if (flags->c == 0)
		ft_putendl_fd("Please put C in a correct format/position", 2);
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

int	check_map_info(char **map, t_flags *flags)
{
	int	i;

	i = 0;
	init_flags(flags);
	//while (map[i] != NULL)
	while (map[i] != NULL && i < 6)
	{
		if (set_flags(map[i], flags) == 1)
			return (1);
		i++;
	}
	if (flags->all_flags == 6)
		return (0);
	else
		print_missing_flags(flags);
	return (1);
}
