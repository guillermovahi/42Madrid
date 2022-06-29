/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:02:20 by guvargas          #+#    #+#             */
/*   Updated: 2022/06/20 19:20:34 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long int	bad_numbers(unsigned long long int z, int y)
{
	unsigned long long int	bad_number;

	bad_number = 9223372036854775806;
	if (z > bad_number + 1 && y < 0)
		return (0);
	if (z > bad_number && y > 0)
		return (-1);
	return (z);
}

int	ft_atoi(const char *str)
{
	int						i;
	int						y;
	unsigned long long int	z;

	i = 0;
	y = 1;
	z = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			y *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		z = (str[i] - '0') + (z * 10);
		i++;
	}
	z = bad_numbers(z, y);
	return (z * y);
}
