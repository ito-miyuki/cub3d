/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_2darray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:15:53 by mito              #+#    #+#             */
/*   Updated: 2024/08/30 15:58:38 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int count_2darray_size(char **src)
{
	int i;

	i = 0;
	while (src[i] != NULL)
		i++;
	return (i);
}

char **copy_2darray(char **src)
{
    char	**copy;
    int		size;
    int		i;
    int		j;

    i = 0;
    size = count_2darray_size(src);
    copy = malloc(sizeof(char *) * (size + 1));
    if (!copy)
        return (NULL);
    while (src[i] != NULL)
    {
        copy[i] = malloc(sizeof(char) * (ft_strlen(src[i]) + 1));
        if (!copy[i])
        {
            while (i > 0)
                free(copy[--i]);
            free(copy);
            return (NULL);
        }
        j = 0;
        while (src[i][j] != '\0')
        {
            copy[i][j] = src[i][j];
            j++;
        }
        copy[i][j] = '\0';
        i++;
    }
    copy[i] = NULL;
    return (copy);
}
