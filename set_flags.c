/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:17:44 by mito              #+#    #+#             */
/*   Updated: 2024/09/26 11:50:54 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

static int set_flag(int *flag, t_flags *flags)
{
    if (*flag == 1)
        return (1);
    *flag = 1;
    flags->all_flags += 1;
    return (0);
}

int	set_flags(char *line, t_flags *flags)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (set_flag(&flags->no, flags));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (set_flag(&flags->so, flags));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (set_flag(&flags->we, flags));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (set_flag(&flags->ea, flags));
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (set_flag(&flags->f, flags));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (set_flag(&flags->c, flags));
	return (0);
}
