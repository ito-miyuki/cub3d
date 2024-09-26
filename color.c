/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:37:20 by mito              #+#    #+#             */
/*   Updated: 2024/09/26 12:26:58 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
/**
 * Return a color which is defined by `rgba` value.
 */
// unsigned int	color(int r, int g, int b, int a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

//this funstion set alpha 255 as default
// uint32_t color(uint32_t r, uint32_t g, uint32_t b)
// {
//     return (255 << 24 | b << 16 | g << 8 | r); // BGRA: Blue, Green, Red, Alpha(255)
// }

uint32_t	color(uint32_t r, uint32_t g, uint32_t b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}
