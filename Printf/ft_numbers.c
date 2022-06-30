/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:44:55 by guvargas          #+#    #+#             */
/*   Updated: 2022/06/30 20:17:15 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_num(int n)
{
	unsigned int	number;
	int				res;

	res = 0;
	if (n < 0)
	{
		res += put_char('-');
		number = -n;
	}
	else
		number = n;
	if (number > 9)
	{
		res += put_num(number / 10);
		number %= 10;
	}
	res += put_char(number + '0');
	return (res);
}

int	put_u_num(unsigned int n)
{
	int				res;

	res = 0;
	if (n < 0)
		n = -n;
	if (n > 9)
	{
		res += put_u_num(n / 10);
		n %= 10;
	}
	res += put_char(n + '0');
	return (res);
}