/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:17:36 by mito              #+#    #+#             */
/*   Updated: 2024/09/03 10:17:47 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
// Use it if you want to make function shorter when you need to skip spaces

void    skip_spaces(char **str)
{
    while (**str == ' ' || **str == '\t')
        (*str)++;
}

char    *skip_spaces(char *str)
{
    while (*str == ' ' || *str == '\t')
        str++;
    return (str);
}
