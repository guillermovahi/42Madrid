/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:05:13 by guvargas          #+#    #+#             */
/*   Updated: 2022/10/02 14:10:54 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//! SSIZE_T READ(INT FILDES, VOID *BUF, SIZE_T NBYTE):
//* Lee NBYTE bytes de datos del objeto referenciado por el FILDES
//* en el buffer apuntado por BUF.

//! RETURNS:
//* N: bytes leídos
//* 0: final de fichero
//* -1: algún error


char	*allocate_memory(size_t size)
{
	char	*buffer;

	buffer = (char *) malloc(sizeof(char) * (size + 1));
	if (buffer == NULL)
		return (NULL);
	return (buffer);
}

char    *get_next_line(int fd)
{
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);

	static char		*buffer;
	static int		res_read;
	char			*returned_line = NULL;
	
	buffer = allocate_memory(BUFFER_SIZE);
	res_read = read(fd, buffer, BUFFER_SIZE);

	if (res_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	
	printf("res_read: %d\n",res_read);
	int i = 0;

	int k = i;
	while(buffer[i] && buffer[i] != '\n' && i < res_read)
		i++;

	int j = -1;
	returned_line = allocate_memory(i);
	while(++j < i)
		returned_line[j] = buffer[k++];
	returned_line[j] = '\0';
	
	printf("returned_line: %s\n", returned_line);
	
	static int buffer_index = 0;
	int l = buffer_index;

	while (buffer[buffer_index] && buffer[buffer_index] != '\n')
	{
		buffer_index++;
		i++;
	}
	returned_line = allocate_memory(i);
	k = ++i;
	i = 0;
	while(i < k)
		returned_line[i++] = buffer[l++];
	returned_line[i] = '\0';
	buffer_index++;
	if (!buffer[buffer_index])
		free(buffer);

	return (returned_line);
}
