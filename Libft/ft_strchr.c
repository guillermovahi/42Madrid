/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:12:38 by guvargas          #+#    #+#             */
/*   Updated: 2022/06/19 22:13:52 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while ((char)s[++i] != '\0')
	{
		if ((char)s[i] == (char)c)
			return (&((char *)s)[i]);
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (0);
}
