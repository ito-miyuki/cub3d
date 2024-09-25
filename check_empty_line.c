/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:59:23 by mito              #+#    #+#             */
/*   Updated: 2024/09/25 13:13:45 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	validate_map_line(char *new_line, int fd)
{
	int	empty;

	empty = 0;
	new_line = get_next_line(fd);
	while (new_line != NULL)
	{
		if (ft_strncmp(new_line, "\n", 1) != 0 && empty == 0)
		{
			free(new_line);
			new_line = get_next_line(fd);
			continue ;
		}
		else if (ft_strncmp(new_line, "\n", 1) == 0)
			empty = 1;
		else if (ft_strncmp(new_line, "\n", 1) != 0 && empty == 1)
		{
			free(new_line);
			print_error(": empty line in map");
			return (1);
		}
		free(new_line);
		new_line = get_next_line(fd);
	}
	return (0);
}

static void	find_last_element(t_game *game, char *new_line, int fd)
{
	if (!game->file_copy || !game->file_copy[5])
		clean_up_exit(game, ": file_copy doesn't have enough line\n");
	new_line = get_next_line(fd);
	while (new_line != NULL)
	{
		if (ft_strncmp(game->file_copy[5],
				new_line, ft_strlen(game->file_copy[5])) == 0)
		{
			free(new_line);
			break ;
		}
		free(new_line);
		new_line = get_next_line(fd);
	}
}

static int	open_file(t_game *game, char *map_file)
{
	int	fd;

	fd = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		clean_up_exit(game, ": read failed\n");
	return (fd);
}

int	check_empty_line(t_game *game, char *map_file)
{
	char	*new_line;
	int		fd;

	new_line = NULL;
	fd = open_file(game, map_file);
	find_last_element(game, new_line, fd);
	new_line = get_next_line(fd);
	while (new_line != NULL && ft_strncmp(new_line, "\n", 1) == 0)
	{
		free(new_line);
		new_line = get_next_line(fd);
	}
	free(new_line);
	if (validate_map_line(new_line, fd) == 1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
