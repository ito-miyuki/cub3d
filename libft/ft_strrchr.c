/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:09:05 by mito              #+#    #+#             */
/*   Updated: 2024/09/30 11:20:46 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	char	*new_str;

	ptr = NULL;
	new_str = (char *)str;
	while (*new_str)
	{
		if (*new_str == (char)c)
			ptr = new_str;
		new_str++;
	}
	if (*new_str == (char)c)
		return (new_str);
	else
		return (ptr);
}
