/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:28:39 by mito              #+#    #+#             */
/*   Updated: 2024/08/28 15:43:51 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// free vector

//realloc vector and copy elements to the new one
static char **realloc_vector(char ***old_data, size_t max_size)
{
	char	**new_data;
	size_t	i;

	i = 0;
	new_data = (char **)malloc(sizeof(char *) * ((max_size * 2) + 1));
	if(new_data == NULL)
		return (NULL);
	while (i < max_size)
	{
		new_data[i] = (char *)old_data[i];
		i++;
	}
	new_data[i] = NULL;
	free(*old_data);
	return (new_data);
}

// re allocate memory to vector and expand its size
static int expand_vector(t_vector *vector)
{
	vector->map_data = realloc_vector(vector, vector->max_size);
	if (vector->map_data == NULL)
		return (1);
	vector->max_size *= 2;
	return (0);
}

// add new elements to vector, if needed add more spaces to it
int	vector_add(t_vector *vector, char *new_data)
{
	if (vector->used_node == vector->max_size)
	{
		if (expand_vector(vector) == 1)
		{
			//free vector
			free(new_data);
			return (1);
		}
	}
	vector->map_data[vector->used_node] = new_data;
	vector->used_node++;
	vector->map_data[vector->used_node] = NULL; // to make array null-ending.
}


t_vector	*init_vector(size_t max_size) // it can be 1 or any numbers
{
	t_vector *vector;

	vector = (t_vector *)malloc(sizeof(t_vector));
	if (vector == NULL)
		print_error_exit(": malloc fail");
	vector->used_node = 0;
	vector->max_size = max_size;
	vector->map_data = (char**)malloc((vector->max_size + 1) * sizeof(char *)); // avoiding teh case: maxsize is 0
	if (vector->map_data == NULL)
	{
		free(vector);
		print_error_exit(": malloc fail");
	}
	vector->map_data[0] = NULL;
	return (vector);
}

