/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:33:46 by alli              #+#    #+#             */
/*   Updated: 2024/09/19 14:47:20 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// this is the original
// void    draw_wall(t_game *game, double lower_p, double upper_p, double wall_h)
// {
//     // uint32_t x;
//     // uint32_t y;

//     // x = game->raycast->index;
//     // y = 0;
//     (void)wall_h;
//     while (upper_p <= lower_p) //wall_h < upper_h
//     {
//         if (game->raycast->is_horizon == 1)
//         {
//             if (game->raycast->ray_angle > 0 && game->raycast->ray_angle < PI) //hitting south txture
//                 mlx_put_pixel(game->canvas, game->raycast->index, upper_p,
//                     color(178, 255, 255));
//             else
//                 mlx_put_pixel(game->canvas, game->raycast->index, upper_p,
//                     color(178, 130, 255));
//         }
//         else
//         {
//             if (game->raycast->ray_angle > PI / 2 && game->raycast->ray_angle < 3 * PI / 2)
//                 mlx_put_pixel(game->canvas, game->raycast->index, upper_p,
//                     color(178, 130, 0));
//             else
//                 mlx_put_pixel(game->canvas, game->raycast->index, upper_p,
//                     color(178, 255, 0));
//         }
//         upper_p++;
//     }
// }


//for testing
static mlx_texture_t *get_texture(t_game *game)
{
	// printf("game->so_texture is %p\n", game->so_texture);
	// printf("game->no_texture is %p\n", game->no_texture);
	// printf("game->we_texture is %p\n", game->we_texture);
	// printf("game->ea_texture is %p\n", game->ea_texture);

    if (game->raycast->is_horizon == 1)
    {
        if (game->raycast->ray_angle > 0 && game->raycast->ray_angle < PI)
		{
			// printf("game->so_texture is %p\n", game->so_texture);
            return (game->so_texture);  // 南の壁 sunflowers
		}
        else
		{
			// printf("game->no_texture is %p\n", game->no_texture);
            return game->no_texture;  // 北の壁 starry night
		}
    }
    else
    {
        if (game->raycast->ray_angle > PI / 2 && game->raycast->ray_angle < 3 * PI / 2)
		{
			// printf("game->we_texture is %p\n", game->we_texture);
            return game->we_texture;   // 西の壁 sunset
		}
        else
		{
			// printf("game->ea_texture is %p\n", game->ea_texture);
            return game->ea_texture;   // 東の壁  girl with the pearl
		}
    }
}

//for testing
static double get_x_offset(mlx_texture_t *texture, t_game *game)
{
    double x_offset;

    if (game->raycast->is_horizon == 1) // 水平方向の壁に当たった場合
    {
        // 壁の南側か北側かに応じてオフセット計算
        // if (game->raycast->ray_angle > 0 && game->raycast->ray_angle < PI)  // 南側の壁
        //     x_offset = game->raycast->h_inter_x - floor(game->raycast->h_inter_x);
        // else // 北側の壁
		// {
        //     x_offset = 1.0 - (game->raycast->h_inter_x - floor(game->raycast->h_inter_x));
		// 	// printf("offset: %f\n", x_offset);
		// 	// printf("game->raycast->h_inter_x: %f\n", game->raycast->h_inter_x);
		// 	// printf("floor of h_inter_x: %f\n", floor(game->raycast->h_inter_x));
		// }
		x_offset = (int)fmodf((game->raycast->h_inter_x * \
		(texture->width / SQ_SIZE)), texture->width);
    }
    else // 垂直方向の壁に当たった場合
    {
        // 壁の東側か西側かに応じてオフセット計算
        // if (game->raycast->ray_angle > PI / 2 && game->raycast->ray_angle < 3 * PI / 2) // 西側の壁
        //     x_offset = 1.0 - (game->raycast->h_inter_y - floor(game->raycast->h_inter_y));
        // else // 東側の壁
        //     x_offset = game->raycast->h_inter_y - floor(game->raycast->h_inter_y);
		x_offset = (int)fmodf((game->raycast->v_inter_y * \
		(texture->width / SQ_SIZE)), texture->width);
    }

    // テクスチャの横幅に合わせてスケーリング
    // x_offset *= texture->width;
	// printf("x_offset at the end: %f\n", x_offset);
    return (x_offset);
}


// experiment with gpt
void    draw_wall(t_game *game, double lower_p, double upper_p, double wall_h)
{
	mlx_texture_t *texture;
	uint32_t *pixels;
	double factor;
	double x_o;
	double y_o;
	int tex_y;

	texture = get_texture(game);

	if (texture == NULL )
	{
        printf("Texture is NULL\n"); // for testing
        return;
    }
	if (texture->pixels == NULL)
	{
        printf("texture->pixels are NULL\n");   // for testing
        return;
    }
	pixels = (uint32_t *)texture->pixels;
	factor = (double)texture->height / wall_h;
	x_o = get_x_offset(texture, game);

	y_o =  (upper_p - (WINDOW_HEIGHT / 2) + (wall_h / 2)) * factor;
	if (y_o < 0)
		y_o = 0;

    while (upper_p < lower_p)
    {
		tex_y = (int)y_o * texture->width + (int)x_o;
        mlx_put_pixel(game->canvas, game->raycast->index, upper_p, pixels[tex_y]);

        y_o += factor;
        upper_p++;
		// tex_y = 0;
    }
}

/*if (vertical_intersection < horizontal_intersection) {
    // Vertical wall hit
    if (ray_dir_x > 0) {
        // Ray moving right
        wall_side = WEST_WALL;
    } else {
        // Ray moving left
        wall_side = EAST_WALL;
    }
} else {
    // Horizontal wall hit
    if (ray_dir_y > 0) {
        // Ray moving down
        wall_side = NORTH_WALL;
    } else {
        // Ray moving up
        wall_side = SOUTH_WALL;
    }
}*/

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
	game->raycast->distance *= cos(adjust_angle(game->raycast->player_angle - game->raycast->ray_angle));
	// printf("distance %f\n", fabs(game->raycast->distance));
	wall_h = fabs((SQ_SIZE / game->raycast->distance) * (WINDOW_WIDTH / 2) / tan(game->raycast->player_fov));
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
