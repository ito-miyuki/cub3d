/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:24:37 by mito              #+#    #+#             */
/*   Updated: 2024/08/22 17:39:47 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "MLX42.h"

# include <fcntl.h>

typedef struct s_map
{
	//mlx_t *mlx; // do we need it?
	char	**grid;
	int		player_x;
	int		player_y;
	int		width;
	int		height;
} t_map;

int		read_map(char *map);
void	print_error_exit(char *message);
void	map_validation(char *map);

#endif
