/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:20:27 by guvargas          #+#    #+#             */
/*   Updated: 2022/06/30 20:16:16 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


size_t	ft_strlen(const char *s);

int	put_char(char c);
int	put_str(char *s);

int	put_num(int n);
int	put_u_num(unsigned int n);

char	*invert_string(char *str, int size);
int	get_hex_length(unsigned int num);
char	*parse_to_hex(unsigned int num);
void	to_upper(char *str);
int	put_hex(unsigned int num, int style);

int	check(va_list params, char const *str, int i);
int ft_printf(char const *str, ...);
