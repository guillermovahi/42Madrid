/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:26:59 by guvargas          #+#    #+#             */
/*   Updated: 2022/06/22 13:39:14 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_words(char const *s, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (*s)
	{
		if (s[i] != c)
			word++;
		i++;
		while (s[i] != '\0')
		{
			if (s[i] != c && s[i - 1] == c)
				word++;
			i++;
		}
	}
	return (word);
}

static char	*mem_fill2(char const *s, int i, int size, char c)
{
	int		j;
	char	*str_res;

	j = -1;
	str_res = (char *)malloc(sizeof(char) * size);
	if (str_res == NULL)
		return (NULL);
	while (s[i] != c && s[i] != '\0')
		str_res[++j] = s[i++];
	str_res[++j] = '\0';
	return (str_res);
}

static int	get_nex_index(char const *s, char c, int word)
{
	int	i;
	int	index;
	int	n_words;

	n_words = 0;
	index = 0;
	i = 0;
	if (s[i] != c)
		n_words++;
	i++;
	while (s[i] != '\0' && n_words < word)
	{
		if (s[i] != c && s[i - 1] == c)
		{
			n_words++;
			index = i;
		}
		i++;
	}
	return (index);
}

static char	*mem_fill1(char const *s, char c, int word)
{
	int		size;
	char	*str_res;
	int		i;
	int		index;

	index = get_nex_index(s, c, word);
	i = index;
	while (s[i] != c && s[i] != '\0')
		i++;
	size = i - index + 1;
	i = index;
	str_res = mem_fill2(s, i, size, c);
	return (str_res);
}

char	**ft_split(char const *s, char c)
{
	size_t	double_array_size;
	char	**arr_of_strings;
	size_t	i;
	int		words;

	if (!s)
		return (NULL);
	words = 1;
	double_array_size = n_words(s, c);
	arr_of_strings = (char **) malloc(sizeof(char *) * (double_array_size + 1));
	if (arr_of_strings == NULL)
		return (NULL);
	i = -1;
	while (++i < double_array_size)
		arr_of_strings[i] = mem_fill1(s, c, words++);
	arr_of_strings[i] = NULL;
	return (arr_of_strings);
}
