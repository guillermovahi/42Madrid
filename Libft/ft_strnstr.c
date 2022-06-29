/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:18:21 by guvargas          #+#    #+#             */
/*   Updated: 2022/06/20 17:52:46 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	aux;

	if (s2[0] == '\0')
		return ((char *)s1);
	i = -1;
	while (s1[++i])
	{
		j = 0;
		if (s1[i] == s2[0])
		{
			aux = i;
			while (s1[i] == s2[j++] && i++ < len)
			{
				if (s2[j] == '\0')
					return ((char *)s1 + aux);
			}
			i = aux;
		}
	}
	return (0);
}
