/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:48:21 by mito              #+#    #+#             */
/*   Updated: 2024/08/30 15:58:25 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void init_flags(t_flags *flags)
{
	flags->no = 0;
	flags->so = 0;
	flags->we = 0;
	flags->ea = 0;
	flags->f = 0;
	flags->c = 0;
	flags->all_flags = 0;
}

static void	set_flag(char *line, char *prefix, int *flag, int *all_flags)
{
	if (ft_strncmp(line, prefix, ft_strlen(prefix)) == 0 && *flag == 0)
	{
		*flag = 1;
		*all_flags += 1;
	}
}


int	check_map_info(char **map, t_flags *flags)
{
	int i;

	i = 0;
	init_flags(flags);
	while (map[i] != NULL && i < 6)
	{
		set_flag(map[i], "NO ", &flags->no, &flags->all_flags);
		set_flag(map[i], "SO ", &flags->so, &flags->all_flags);
		set_flag(map[i], "WE ", &flags->we, &flags->all_flags);
		set_flag(map[i], "EA ", &flags->ea, &flags->all_flags);
		set_flag(map[i], "F ", &flags->f, &flags->all_flags);
		set_flag(map[i], "C ", &flags->c, &flags->all_flags);
		i++;
	}
	if (flags->all_flags == 6)
		return (0);
	return (1);
}



// int	check_map_info(char **map, t_flags *flags)
// {
// 	int i;

// 	i = 0;
// 	init_flags(flags);
// 	while (map[i] != NULL && i < 6)
// 	{
// 		if (ft_strncmp(map[i], "NO ", 3) == 0 && flags->no == 0)
// 		{
// 			flags->no = 1;
// 			flags->all_flags += 1;
// 		}
// 		else if (ft_strncmp(map[i], "SO ", 3) == 0 && flags->so == 0)
// 		{
// 			flags->so = 1;
// 			flags->all_flags += 1;
// 		}
// 		else if (ft_strncmp(map[i], "WE ", 3) == 0 && flags->we == 0)
// 		{
// 			flags->we = 1;
// 			flags->all_flags += 1;
// 		}
// 		else if (ft_strncmp(map[i], "EA ", 3) == 0 && flags->ea == 0)
// 		{
// 			flags->ea = 1;
// 			flags->all_flags += 1;
// 		}
// 		else if (ft_strncmp(map[i], "F ", 2) == 0 && flags->f == 0)
// 		{
// 			flags->f = 1;
// 			flags->all_flags += 1;
// 		}
// 		else if (ft_strncmp(map[i], "C ", 2) == 0 && flags->c == 0)
// 		{
// 			flags->c = 1;
// 			flags->all_flags += 1;
// 		}
// 		i++;
// 	}
// 	if (flags->all_flags == 6)
// 		return (0);
// 	return (1);
// }
