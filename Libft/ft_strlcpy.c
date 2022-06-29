/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:25:20 by guvargas          #+#    #+#             */
/*   Updated: 2022/06/22 00:19:29 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	if (size != 0)
	{
		while ((src[i] != '\0') && (i < size - 1))
		{
			dest[i] = src[i];
			i ++;
		}
		dest[i] = '\0';
	}
	while (src[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}
