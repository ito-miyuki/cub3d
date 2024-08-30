/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:24:37 by mito              #+#    #+#             */
/*   Updated: 2024/08/30 15:56:35 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "MLX42.h"

# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h> // for printf, delete it

typedef struct s_flags
{
	int no;
	int so;
	int we;
	int ea;
	int f;
	int c;
	int all_flags;
}	t_flags;


typedef struct s_game
{
	char	*filename;
	char	**map;
	char	**file_copy;
	t_flags *info_flags;
	size_t	height;
	size_t	width;
	size_t	player_x;
	size_t	player_y;
	//mlx_t	*mlx;
}	t_game;

void	print_error_exit(char *message);
void	init_game(t_game *game, char *map);
char	**create_2darray(char *map_file);
int		check_map_info(char **map, t_flags *flags);
char	**copy_2darray(char **src);
void	free_grid(char **grid);


#endif
