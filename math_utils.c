/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:53:43 by alli              #+#    #+#             */
/*   Updated: 2024/09/11 10:08:15 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//  cos(x), sin(x), and tan(x) return the cosine, sine and tangent of x,
    //  respectively.  Note that x is interpreted as specifying an angle in
    //  radians.
     
float  adjust_angle(double angle)
{
    if (angle < 0)
	{
        angle += 2 * PI;
		return (angle);
	}
    if (angle >= 2 * PI)
	{
        angle -= 2 * PI;
		return (angle);
	}
	return (angle);
}

// float adjust_angle(double *angle)
// {
//     *angle = fmod(*angle, 2 * PI);
//     if (*angle < 0)
//         *angle += 2 * PI;
//     return (float)(*angle);
// }