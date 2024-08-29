/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_2darray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:09:02 by mito              #+#    #+#             */
/*   Updated: 2024/08/29 12:24:12 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char **create_2darray(char *map_file)
{
	char	*map_str;
	char	**map_array;

	map_str = read_map(map_file);
	if (map_str == NULL)
		print_error_exit(": read map error"); // do I need to free something
	map_array = ft_split(map_str, '\n');
	if (!map_array)
	{
		free(map_str);
		error_message("malloc failed");
	}
	return (map_array);
}

map_str = read_map(map_file); // remove empty line from here
	if (map_str == NULL)
		exit(EXIT_FAILURE); // change it
	map_array = ft_split(map_str, '\n');
	if (!map_array)
	{
		free(map_str); // think again about freeing things
		print_error_exit(": malloc failed");
	}
