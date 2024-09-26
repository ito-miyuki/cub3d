/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_2darray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:15:53 by mito              #+#    #+#             */
/*   Updated: 2024/09/20 18:11:22 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	copy_string(char **copy, char *src, int i)
{
	int	j;

	copy[i] = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!copy[i])
		return (0);
	j = 0;
	while (src[j] != '\0')
	{
		copy[i][j] = src[j];
		j++;
	}
	copy[i][j] = '\0';
	return (1);
}

char	**copy_2darray(char **src)
{
	char	**copy;
	int		size;
	int		i;

	i = 0;
	size = count_2darray_size(src);
	copy = malloc(sizeof(char *) * (size + 1));
	if (!copy)
		return (NULL);
	while (src[i] != NULL)
	{
		if (!copy_string(copy, src[i], i))
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
