/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:26:37 by guvargas          #+#    #+#             */
/*   Updated: 2022/06/22 00:20:42 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	size;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		size = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[size - 1] && ft_strchr(set, s1[size - 1]) && size > i)
			size--;
		str = (char *) malloc(sizeof(char) * (size - i + 1));
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, &s1[i], size - i + 1);
	}
	return (str);
}
