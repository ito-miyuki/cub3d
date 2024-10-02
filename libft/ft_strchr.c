/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:15:54 by mito              #+#    #+#             */
/*   Updated: 2024/09/30 11:20:13 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*newstr;

	newstr = (char *)str;
	while (*newstr != (char)c)
	{
		if (*newstr == '\0')
			return (NULL);
		newstr++;
	}
	return (newstr);
}
