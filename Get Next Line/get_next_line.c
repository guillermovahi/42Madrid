/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:05:13 by guvargas          #+#    #+#             */
/*   Updated: 2022/06/26 23:45:01 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{

    int i = 0;
    char c;
    char *s = malloc(20);
    
    read(fd, &c, 1);
    while(c != '\n' )
    {
        read(fd, &c, 1);
        printf("letter: %c\n",c);
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return s;
}

