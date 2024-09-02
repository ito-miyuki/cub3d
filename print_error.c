/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:31:38 by mito              #+#    #+#             */
/*   Updated: 2024/08/22 16:00:44 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	print_error(char *message)
// {
// 	ft_putstr_fd("Error", 2);
// 	if (message)
// 		ft_putstr_fd(message, 2);
// 	ft_putstr_fd("\n", 2);
// }

void	print_error_exit(char *message)
{
	ft_putstr_fd("Error", 2);
	if (message)
		ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}
