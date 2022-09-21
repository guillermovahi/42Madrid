/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:05:13 by guvargas          #+#    #+#             */
/*   Updated: 2022/08/29 20:15:17 by guvargas         ###   ########.fr       */
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

char    *get_next_line(int fd)
{

	//TODO: declarar dos punteros: 1 fijo (estático) | 1 temporal auxiliar
	//TODO: se copia la dirección inicial de memoria del puntero estatico y 
	//TODO: se avanza primero con el estático, para sacar el tamaño del string
	//TODO: a devolver y hacer malloc. se recorre de nuevo para almacenar la linea

	//* Comprobaciones necesarias 
	//* man page -> open() returns a file descriptor, a small, nonnegative integer.
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);

	char		*buffer;
	ssize_t		res_read;
	
	//TODO: A la hora de reservar memoria para el buffer necesito reservar +1?
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	
	res_read = read(fd, buffer, BUFFER_SIZE);
	if (res_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[res_read] = '\0';

	return (buffer);
}

