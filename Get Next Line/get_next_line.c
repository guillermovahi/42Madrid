/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:05:13 by guvargas          #+#    #+#             */
/*   Updated: 2022/07/11 21:53:37 by guvargas         ###   ########.fr       */
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

	char		*res;
	ssize_t		res_read;
	
	res = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (res == NULL)
		return (NULL);
	
	res_read = read(fd, res, BUFFER_SIZE);
	if (res_read == -1)
	{
		free(res);
		return (NULL);
	}
	
	res[res_read] = '\0';
	
	

	return res;
}

