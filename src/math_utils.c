/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:53:43 by alli              #+#    #+#             */
/*   Updated: 2024/10/01 13:35:40 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	adjust_angle(double angle)
{
	if (angle <= 0)
	{
		angle += 2 * PI;
		return (angle);
	}
	if (angle > 2 * PI)
	{
		angle -= 2 * PI;
		return (angle);
	}
	return (angle);
}

float	distance(t_game *game, float x, float y)
{
	float	new_x;
	float	new_y;
	float	distance;

	new_x = x - game->raycast->p_x;
	new_y = y - game->raycast->p_y;
	distance = sqrt(pow(new_x, 2) + (pow(new_y, 2)));
	return (distance);
}

double	get_x_offset(mlx_texture_t *texture, t_game *game)
{
	double	x_offset;

	if (game->raycast->is_horizon == 1)
	{
		x_offset = (int)fmodf((game->raycast->h_inter_x
					* (texture->width / SQ_SIZE)), texture->width);
	}
	else
		x_offset = (int)fmodf((game->raycast->v_inter_y
					* (texture->width / SQ_SIZE)), texture->width);
	return (x_offset);
}
