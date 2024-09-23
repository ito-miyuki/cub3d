/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:59:23 by mito              #+#    #+#             */
/*   Updated: 2024/09/23 12:02:51 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static int has_empty_line()
// {
// 	while ((new_line = get_next_line(fd))) // here is the map starting point
// 	{
// 		if (ft_strncmp(new_line, "\n", 1) != 0 && empty == 0)
// 			continue;
// 		else if (ft_strncmp(new_line, "\n", 1) == 0)
// 		{
// 			empty = 1;
// 			continue ;
// 		}
// 		else if (ft_strncmp(new_line, "\n", 1) != 0 && empty == 1)
// 		{
// 			free(new_line);
// 			close(fd);
// 			print_error(": empty line in map");
// 			return (1);
// 		}
// 		free(new_line);
// 	}
// }


// int	check_empty_line(t_game *game, char *map_file)
// {
// 	char	*new_line;
// 	int		fd;
// 	int		empty;

// 	empty = 0;
// 	fd = open(map_file, O_RDONLY);
// 	if (fd == -1)
// 		clean_up_exit(game, ": read failed\n");
// 	while ((new_line = get_next_line(fd)))
// 	{
// 		// think about safer idea
// 		if (ft_strncmp(game->file_copy[5], new_line, ft_strlen(game->file_copy[5])) == 0) // that's the validation starting point
// 		{
// 			free(new_line);
// 			break;
// 		}
// 		free(new_line);
// 	}
// 	while ((new_line = get_next_line(fd))&& ft_strncmp(new_line, "\n", 1) == 0) // skip smpty line between map and info
// 		free(new_line);
// 	while ((new_line = get_next_line(fd))) // here is the map starting point
// 	{
// 		if (ft_strncmp(new_line, "\n", 1) != 0 && empty == 0)
// 			continue;
// 		else if (ft_strncmp(new_line, "\n", 1) == 0)
// 		{
// 			empty = 1;
// 			continue ;
// 		}
// 		else if (ft_strncmp(new_line, "\n", 1) != 0 && empty == 1)
// 		{
// 			free(new_line);
// 			close(fd);
// 			print_error(": empty line in map");
// 			return (1);
// 		}
// 		free(new_line);
// 	}
// 	close(fd);
// 	return (0);
// }

int	check_empty_line(t_game *game, char *map_file)
{
	char	*new_line;
	int		fd;
	int		empty;

	empty = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		clean_up_exit(game, ": read failed\n");
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
		free(new_line);
	while ((new_line = get_next_line(fd))) // here is the map starting point
	{
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
			close(fd); // add error handling
			print_error(": empty line in map");
			return (1);
		}
		free(new_line);
	}
	close(fd); // add error handling
	return (0);
}
