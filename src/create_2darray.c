/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_2darray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:09:02 by mito              #+#    #+#             */
/*   Updated: 2024/09/26 17:09:54 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*read_map_from_file(int fd)
{
	char	*new_line;
	char	*line_joint;
	char	*temp;

	line_joint = ft_calloc(1, 1);
	if (!line_joint)
		return (NULL);
	new_line = get_next_line(fd);
	while (new_line)
	{
		temp = line_joint;
		line_joint = ft_strjoin(line_joint, new_line);
		if (!line_joint)
		{
			free(temp);
			free(new_line);
			return (NULL);
		}
		free(new_line);
		free(temp);
		new_line = get_next_line(fd);
	}
	return (line_joint);
}

static char	*read_map(char *map_file)
{
	int		fd;
	char	*map_string;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_string = read_map_from_file(fd);
	close(fd);
	return (map_string);
}

char	**create_2darray(char *map_file)
{
	char	*map_str;
	char	**map_array;

	map_str = read_map(map_file);
	if (!map_str)
	{
		print_error("read map error");
		return (NULL);
	}
	map_array = ft_split(map_str, '\n');
	free(map_str);
	if (!map_array)
	{
		return (NULL);
		print_error_exit("malloc failed");
	}
	return (map_array);
}
