/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:44:47 by guvargas          #+#    #+#             */
/*   Updated: 2022/07/01 17:08:53 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	caracter;

	caracter = 0;
	while (s[caracter] != '\0')
		caracter++;
	return (caracter);
}

int	put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	put_str(char *s)
{
	if (s == NULL)
	{
		write(1, "(null)", ft_strlen("(null)"));
		return (ft_strlen("(null)"));
	}
	else
	{
		write(1, s, ft_strlen(s));
		return (ft_strlen(s));
	}
}
