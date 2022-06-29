/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:05:00 by guvargas          #+#    #+#             */
/*   Updated: 2022/06/22 16:25:16 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_length;
	size_t	j;
	size_t	src_length;

	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	if (size < dest_length + 1)
		return (src_length + size);
	j = 0;
	while (j < (size - dest_length - 1) && src[j] != '\0')
	{
		dest[j + dest_length] = src[j];
		j++;
	}
	dest[j + dest_length] = '\0';
	return (src_length + dest_length);
}
