/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:13:46 by guvargas          #+#    #+#             */
/*   Updated: 2022/06/20 15:36:39 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	while (--i > -1)
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
	}
	return (0);
}
