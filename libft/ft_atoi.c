/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:44:36 by mito              #+#    #+#             */
/*   Updated: 2024/09/30 10:43:04 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overflow(long res, int digit)
{
	if (res > LONG_MAX / 10)
		return (1);
	else if (res * 10 > (LONG_MAX - digit))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	res;
	int			negative;

	res = 0;
	negative = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		if (check_overflow(res, *str - '0') == 1 && negative == -1)
			return (0);
		if (check_overflow(res, *str - '0') == 1 && negative == 1)
			return (-1);
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((int)res * negative);
}
