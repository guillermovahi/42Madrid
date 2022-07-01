/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:20:27 by guvargas          #+#    #+#             */
/*   Updated: 2022/07/01 16:44:29 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

# define HL "0123456789abcdef"
# define HU "0123456789ABCDEF"

size_t	ft_strlen(const char *s);

int	put_char(char c);
int	put_str(char *s);

int	put_num(int n);
int	put_u_num(unsigned int n);

char	*invert_string(char *str, int size);
int	get_hex_length(unsigned int num);
char	*parse_to_hex(unsigned int num);
void	to_upper(char *str);
int	put_hex(unsigned int num, char type);
int	put_pointer(unsigned long int num, int times);

int	check(va_list params, char const *str, int i);
int ft_printf(char const *str, ...);
