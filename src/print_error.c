/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:31:38 by mito              #+#    #+#             */
/*   Updated: 2024/09/20 16:36:10 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_error(char *message)
{
	ft_putendl_fd("Error", 2);
	if (message)
		ft_putstr_fd(message, 2);
}

void	print_error_exit(char *message)
{
	ft_putendl_fd("Error", 2);
	if (message)
		ft_putendl_fd(message, 2);
	exit(1);
}
