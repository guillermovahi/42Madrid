/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:11:42 by guvargas          #+#    #+#             */
/*   Updated: 2022/06/20 11:46:28 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = -1;
	if (dst > src)
		while (len-- > 0)
			((char *)dst)[len] = ((char *)src)[len];
	else
	{
		while (++i < len)
			((char *)dst)[i] = ((char *)src)[i];
	}
	return (dst);
}
