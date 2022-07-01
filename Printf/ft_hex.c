/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:44:29 by guvargas          #+#    #+#             */
/*   Updated: 2022/07/01 17:02:40 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex(unsigned int num, char type)
{	
	int		count;
	char	*base;

	count = 0;
	base = HL;
	if (type == 'U')
		base = HU;
	if (num < 16)
		count += put_char(*(base + num));
	if (num >= 16)
	{
		count += put_hex(num / 16, type);
		count += put_hex(num % 16, type);
	}
	return (count);
}

int	put_pointer(unsigned long int num, int times)
{	
	int		count;
	char	*base;

	count = 0;
	base = HL;
	if (times++ == 1)
		count += put_str("0x");
	if (num < 16)
		count += put_char(*(base + num));
	if (num >= 16)
	{
		count += put_pointer(num / 16, times);
		count += put_pointer(num % 16, times);
	}
	return (count);
}
