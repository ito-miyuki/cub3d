/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:56:12 by mito              #+#    #+#             */
/*   Updated: 2024/09/18 13:44:28 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_grid(char **grid)
{
	size_t	i;

	i = 0;
	if (grid == NULL)
		return ;
	while (grid[i] != NULL)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	grid = NULL; // do I need it?
}
