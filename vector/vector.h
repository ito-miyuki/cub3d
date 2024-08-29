/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:58:00 by mito              #+#    #+#             */
/*   Updated: 2024/08/28 14:57:59 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <stdlib.h>

typedef struct s_vector
{
	char	**map_data; // a pointer to data array
	size_t	used_node; // number of current elements that is stored
	size_t	max_size; // max size of the map vector
}	t_vector;

t_vector	*init_vector(size_t max_size);


#endif
