/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:44:29 by guvargas          #+#    #+#             */
/*   Updated: 2022/06/29 15:55:30 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*invert_string(char *str, int size)
{
	char	*res;
	int		j;

	j = 0;
	res = (char *) malloc(sizeof(char) * (size + 1) );
	if (res == NULL)
		return (NULL);
	while (--size > -1)
		res[j++] = str[size];
	res[j] = 0;
	return (res);
}

int	get_hex_length(unsigned int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

void	to_upper(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
}

char	*parse_to_hex(unsigned int num)
{
	char			*res;
	unsigned int	aux;
	int				i;

	if (num == 0)
		return ("0");

	i = get_hex_length(num);
	res = (char *) malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return NULL;
	i = 0;
	while (num != 0)
	{
		aux = num % 16;
		if (aux < 10)
			aux += 48;
		else
			aux += 87;
		res[i++] = aux;
		num /= 16;
	}
	return invert_string(res, i);
}


int	put_hex(unsigned int num, int style)
{
	char	*str;
	int		size;

	size = 0;
	if (style == 2)
		size += put_str("0x");
	str = parse_to_hex(num);
	if (style == 1)
		to_upper(str);
	size += put_str(str);
	//free(str);
	return (size);
}