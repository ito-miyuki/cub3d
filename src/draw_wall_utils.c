/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:37:54 by alli              #+#    #+#             */
/*   Updated: 2024/09/27 10:22:30 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_texture(mlx_texture_t *texture)
{
	if (texture == NULL)
		return (0);
	if (!texture->pixels)
		return (0);
	return (1);
}

int	norm_color(int c)
{
	unsigned char	bytes[4];
	int				reversed;
	unsigned char	reversed_bytes[4];

	ft_memcpy(bytes, &c, sizeof(int));
	reversed_bytes[0] = bytes[3];
	reversed_bytes[1] = bytes[2];
	reversed_bytes[2] = bytes[1];
	reversed_bytes[3] = bytes[0];
	ft_memcpy(&reversed, reversed_bytes, sizeof(int));
	return (reversed);
}
