/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:05:13 by guvargas          #+#    #+#             */
/*   Updated: 2022/07/06 16:02:11 by guvargas         ###   ########.fr       */
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

	static char	orig;
	char		temp;
	char		*res;
	int		bytes;
	int			i;

	bytes = 0;
	i = -1;
	temp = orig;
	while(read(fd, &orig, sizeof(orig)) > 0)
	{
		bytes++;
		// res[i] = c;
		// printf("letter [%d]: %c\n",i,c);        
		if (orig == '\n')
			break;
		//i++;
	}
	res = (char *) malloc(sizeof(char) * (bytes + 1));
	while(++i < bytes)
	{
		read(fd, &temp, sizeof(temp));
		res[i] = temp;
		// printf("letter [%d]: %c\n",i,c);        
		if (temp == '\n')
			break;
		//i++;
	}
	res[i] = '\0';
	printf("bytes: %d\n", bytes);
	//s[i] = '\0';
	return res;
}

