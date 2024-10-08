/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_2darray_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:45:47 by mito              #+#    #+#             */
/*   Updated: 2024/09/20 17:57:16 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	count_2darray_size(char **src)
{
	int	i;

	i = 0;
	while (src[i] != NULL)
		i++;
	return (i);
}
