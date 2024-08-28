/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:24:37 by mito              #+#    #+#             */
/*   Updated: 2024/08/28 11:25:16 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "MLX42.h"

# include <fcntl.h>
# include <stdlib.h>

typedef struct s_map
{
	//mlx_t *mlx; // do we need it?
	char	**grid;
	size_t	player_x;
	size_t	player_y;
	size_t	width;
	size_t	height;
} t_map;

int		read_map(char *map);
void	print_error_exit(char *message);
//void	map_validation(char *map);
t_map	*init_map(char *map);

#endif
