/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:23:36 by alli              #+#    #+#             */
/*   Updated: 2024/09/27 13:23:57 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
	{
		return (1);
	}
	else
		return (0);
}

static int	check_longint(long num, int dig)
{
	long long	llong_max;

	llong_max = 9223372036854775807;
	if (num > llong_max / 10)
		return (1);
	else if (num * 10 > llong_max - dig)
		return (1);
	return (0);
}

static int	str_char_check(const char *str)
{
	int	i;

	i = 0;
	if (!ft_digit((char *)str))
		return (-1);
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\v'
		|| str[i] == '\t' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (i == '\0')
		return (0);
	else
		return (-1);
}

long	ft_atol(const char *str)
{
	long			total;
	int				i;

	total = 0;
	i = 0;
	if (str_char_check(str) == -1)
		return (-1);
	if (((str[i] == '+') || str[i] == '-') && str[i])
		return (-1);
	while (str[i])
	{
		if (check_longint(total, str[i] - '0'))
			return (-1);
		total = total * 10 + (str[i++] - '0');
	}
	return (total);
}
