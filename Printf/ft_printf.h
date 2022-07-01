/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:20:27 by guvargas          #+#    #+#             */
/*   Updated: 2022/07/01 17:14:58 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Librerías
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

// Macros
# define HL "0123456789abcdef"
# define HU "0123456789ABCDEF"

// Funciones
size_t	ft_strlen(const char *s);
int		put_char(char c);
int		put_str(char *s);
int		put_num(int n);
int		put_u_num(unsigned int n);
int		put_hex(unsigned int num, char type);
int		put_pointer(unsigned long int num, int times);
int		check(va_list params, char const *str, int i);
int		ft_printf(char const *str, ...);

#endif