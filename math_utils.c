/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:53:43 by alli              #+#    #+#             */
/*   Updated: 2024/09/03 10:07:22 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//  cos(x), sin(x), and tan(x) return the cosine, sine and tangent of x,
    //  respectively.  Note that x is interpreted as specifying an angle in
    //  radians.
     
double ft_tan(int degree)
{
    double rad;
    double output;
    
    rad = degree * PI / 180;
    output = tan(rad);
    return (output);
}

double ft_cos(int degree)
{
    double rad;
    double output;

    rad = degree * PI / 180;
    output = (cos(rad));
    return (output);
}

double player_angle()
{
    
    PI / 2 - FOV/2;
}
/*

*/