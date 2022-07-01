/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:53:41 by guvargas          #+#    #+#             */
/*   Updated: 2022/07/01 17:07:35 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(va_list params, char const *str, int i)
{
	int	pchars;

	pchars = 0;
	if (str[i] == 'c')
		pchars += put_char(va_arg(params, int));
	else if (str[i] == 's')
		pchars += put_str(va_arg(params, char *));
	else if (str[i] == 'p')
		pchars += put_pointer((unsigned long int)va_arg(params, void *), 1);
	else if (str[i] == 'd' || str[i] == 'i')
		pchars += put_num(va_arg(params, int));
	else if (str[i] == 'u')
		pchars += put_u_num(va_arg(params, unsigned int));
	else if (str[i] == 'x')
		pchars += put_hex(va_arg(params, unsigned int), 'L');
	else if (str[i] == 'X')
		pchars += put_hex(va_arg(params, unsigned int), 'U');
	else if (str[i] == '%')
		pchars += put_char('%');
	else
		return (-1);
	return (pchars);
}

int	ft_printf(char const *str, ...)
{
	int		res;
	int		i;
	va_list	params;

	i = -1;
	res = 0;
	va_start(params, str);
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
			res += check(params, str, ++i);
		else
			res += put_char(str[i]);
	}
	va_end(params);
	return (res);
}
