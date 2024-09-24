/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:33:46 by alli              #+#    #+#             */
/*   Updated: 2024/09/24 16:50:05 by alli             ###   ########.fr       */
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
	// game->raycast->ray_angle = adjust_angle(game->raycast->ray_angle);
    if (game->raycast->is_horizon == 1)
    {
       	if (game->raycast->ray_angle > WEST && game->raycast->ray_angle < EAST)
            return (game->so_texture);  // 南の壁 yunchia
        else
            return (game->no_texture);  // 北の壁 starry night
    }
    else
    {
		if (game->raycast->ray_angle > SOUTH && game->raycast->ray_angle < NORTH)
            return (game->ea_texture);   // 西の壁 sunset
        else
            return (game->we_texture);   // 東の壁  girl with the pearl
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
		x_offset = (int)fmodf((game->raycast->h_inter_x * (texture->width / SQ_SIZE)), texture->width);
		//hitting horizontal wall, so we have to print the x. where along the x axis the ray hit the wall
		// printf("game->h_inter_x: %f\n", game->raycast->h_inter_x);
    }
    else // 垂直方向の壁に当たった場合
    {
        // 壁の東側か西側かに応じてオフセット計算
        // if (game->raycast->ray_angle > PI / 2 && game->raycast->ray_angle < 3 * PI / 2) // 西側の壁
        //     x_offset = 1.0 - (game->raycast->h_inter_y - floor(game->raycast->h_inter_y));
        // else // 東側の壁
        //     x_offset = game->raycast->h_inter_y - floor(game->raycast->h_inter_y);
		// printf("texture->width: %u\n", texture->width);
		x_offset = (int)fmodf((game->raycast->v_inter_y * (texture->width / SQ_SIZE)), texture->width);
		//where along the y-axis the vertical wall is hit. where along the vertical plane it occurs
    }

    // テクスチャの横幅に合わせてスケーリング
    // x_offset *= texture->width;
	// printf("x_offset at the end: %f\n", x_offset);
    return (x_offset);
}

int	norm_color(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
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
        // printf("Texture is NULL\n"); // for testing
        return;
    }
	if (texture->pixels == NULL)
	{
        // printf("texture->pixels are NULL\n");   // for testing
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
        mlx_put_pixel(game->canvas, game->raycast->index, upper_p, norm_color(pixels[tex_y]));
		// printf("pixels[tex_y]: %u\n", pixels[tex_y]);
		// printf("game->raycast->index")
        y_o += factor;
        upper_p++;
		// printf("upper_p: %f\n", upper_p);
		// tex_y = 0;
    }
	// printf("exited draw_wall\n");
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
	game->raycast->distance *= cos(adjust_angle(game->raycast->player_angle - game->raycast->ray_angle));
	// printf("distance %f\n", fabs(game->raycast->distance));
	// printf("render player_angle: %f\n", game->raycast->player_angle);
	wall_h = fabs((SQ_SIZE / game->raycast->distance) * (WINDOW_WIDTH / 2) / tan(game->raycast->player_fov));
	// printf("wall_h 1 in render wall %f\n", wall_h);
    lower_p = (WINDOW_HEIGHT / 2) + (wall_h / 2); //splits the screen in half and calcs the bottom wall
	upper_p = (WINDOW_HEIGHT / 2) - (wall_h / 2); //top part of the screen or wall
	if (lower_p > WINDOW_HEIGHT)
		lower_p = WINDOW_HEIGHT;
	if (upper_p	< 0)
		upper_p = 0;
	game->raycast->index = ray;
	// printf("wall_h 2 in render wall %f\n", wall_h);
	draw_wall(game, lower_p, upper_p, wall_h);
	draw_floor_ceil(game, ray, lower_p, upper_p);
}
