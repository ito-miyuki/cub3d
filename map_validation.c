/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:54:16 by mito              #+#    #+#             */
/*   Updated: 2024/08/29 12:10:27 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static  int has_nsew_only_once(char **map)
{
    int i;
    int j;
    int count;

    i = 0;
    j = 0;
    count = 0;
    while (map[i] != NULL)
    {
        while (map[i][j] != '\0')
        {
            if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
                count++;
            j++;
        }
        i++;
        j = 0;
    }
    if (count == 1)
        return (1);
    return (0);
}

static  int has_only_valid_chars(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i] != NULL)
    {
        while (map[i][j] != '\0')
        {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ' && map[i][j] != '\t' 
                    && map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W')
                return (0);
            j++;
        }
        i++;
        j = 0;
    }
    return (1);
}

int map_validation(t_game *game, char **map)
{
    (void)(game); // delete it
    if (!has_only_valid_chars(map))
    {
        ft_putendl_fd("map contains invalid char", 2);
        exit(1); // exit is for testing. change it to free everything! 
    }
    if (!has_nsew_only_once(map))
    {
        ft_putendl_fd("map can contain NSEW only once", 2);
        exit(1); // exit is for testing. change it to free everything! 
    }
    printf("Nice:D Map DOES NOT contain invalid char");
    return (0);
}
