/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:05:23 by mito              #+#    #+#             */
/*   Updated: 2024/08/29 12:06:57 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*read_map_from_file(int fd)
{
	char	*new_line;
	char	*line_joint;
	char	*temp;

	line_joint = ft_calloc(1, 1);
	if (!line_joint)
		return (NULL);
	while (1)
	{
		temp = line_joint;
		new_line = get_next_line(fd);
		if (new_line)
		{
			line_joint = ft_strjoin(line_joint, new_line);
			free (new_line);
			free (temp);
		}
		else
			break ;
	}
	return (line_joint);
}

char	*read_map(char *map_file)
{
	int		fd;
	char	*map_string;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		error_message("read failed");
	if (errno && errno == 21)
	{
		close(fd);
		perror("Error\n");
		return (NULL);
	}
	map_string = read_map_from_file(fd);
	close(fd);
	return (map_string);
}
