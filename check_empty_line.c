/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:59:23 by mito              #+#    #+#             */
/*   Updated: 2024/09/12 12:20:14 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_empty_line(t_game *game, char *map_file)
{
	char	*new_line;
	int fd;
	int empty;

	empty = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		print_error_exit(": read failed\n");
	while ((new_line = get_next_line(fd)))
	{
		// think about safer idea
		if (ft_strncmp(game->file_copy[5], new_line, ft_strlen(game->file_copy[5])) == 0) // that's the validation starting point
		{
			free(new_line);
			break;
		}
		free(new_line);
	}
	while ((new_line = get_next_line(fd))&& ft_strncmp(new_line, "\n", 1) == 0) // skip smpty line between map and info
	{
		printf("(continue1)new line is: %s\n", new_line);
		free(new_line);
	}
	while ((new_line = get_next_line(fd))) // here is the map starting point
	{
		printf("(continue2)new line is: %s\n", new_line);
		if (ft_strncmp(new_line, "\n", 1) != 0 && empty == 0)
			continue;
		else if (ft_strncmp(new_line, "\n", 1) == 0)
		{
			empty = 1;
			continue ;
		}
		else if (ft_strncmp(new_line, "\n", 1) != 0 && empty == 1)
		{
			free(new_line);
			close(fd);
			print_error_exit(": empty line in map");
		}
		free(new_line);
	}
	close(fd);
	return (0);
}

