/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:33:46 by alli              #+#    #+#             */
/*   Updated: 2024/09/12 10:17:21 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_wall(t_game *game, double lower_p, double upper_p, double wall_h)
{
    // uint32_t x;
    // uint32_t y;

    // x = game->raycast->index;
    // y = 0;
    (void)wall_h;
    while (upper_p <= lower_p) //wall_h < upper_h
    {
		if (game->raycast->is_horizon == 1)
			mlx_put_pixel(game->canvas, game->raycast->index, upper_p,
				color(178, 255, 0));
		else
			mlx_put_pixel(game->canvas, game->raycast->index, upper_p,
				color(178, 255, 254));
		upper_p++;
	}
}
void	draw_floor_ceil(t_game *game, int ray, double lower_p, double upper_p) // double wall_h
{
	uint32_t ceil;

	ceil = 0;
    while (ceil < upper_p)
    {
        mlx_put_pixel(game->canvas, ray, ceil,
				color(game->ceiling_r, game->ceiling_g, game->ceiling_b));
		ceil++;
    }
	//printf("ceiling color is: r %d g %d b %d\n", game->ceiling_r, game->ceiling_g, game->ceiling_b);
	while (lower_p < WINDOW_HEIGHT)
    {
            mlx_put_pixel(game->canvas, ray, lower_p,
				color(game->floor_r, game->floor_g, game->floor_b));
       lower_p++;
    }
	// printf("floor color is: r %d g %d b %d\n", game->floor_r, game->floor_g, game->floor_b);
}

void	render_wall(t_game *game, int ray)
{
	double	wall_h;
	double	lower_p;
	double	upper_p;
	
    wall_h = 0;
	game->raycast->distance *= cos(adjust_angle(game->raycast->ray_angle - game->raycast->player_angle)); 
	// printf("distance %f\n", fabs(game->raycast->distance));
	wall_h = fabs((SQ_SIZE / game->raycast->distance) * (WINDOW_WIDTH / 2) / tan(game->raycast->player_fov / 2));
	// printf("wall_h 1 in render wall %f\n", wall_h);
    lower_p = (WINDOW_HEIGHT / 2) + (wall_h / 2); //splits the screen in half and calcs the bottom wall
	upper_p = (WINDOW_HEIGHT / 2) - (wall_h / 2); //top part of the screen
	if (lower_p > WINDOW_HEIGHT)
		lower_p = WINDOW_HEIGHT;
	if (upper_p	< 0)
		upper_p = 0;
	game->raycast->index = ray;
	draw_wall(game, lower_p, upper_p, wall_h);
	draw_floor_ceil(game, ray, lower_p, upper_p);
}