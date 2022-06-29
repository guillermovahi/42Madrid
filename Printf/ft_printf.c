/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:53:41 by guvargas          #+#    #+#             */
/*   Updated: 2022/06/29 00:26:21 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	caracter;

	caracter = 0;
	while (s[caracter] != '\0')
		caracter++;
	return (caracter);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
	{
		write(fd, "(null)", ft_strlen("(null)"));	
		return ft_strlen("(null)");
	}
	else
	{
		write(fd, s, ft_strlen(s));	
		return ft_strlen(s);
	}
}
char	*parseToHex(unsigned int num)
{
	char		*res;
	unsigned int	aux;
	int			i;
	int			j;
	char		*temp;
	unsigned int			otro_aux;
	i = 0;	
	otro_aux = num;
	while (otro_aux != 0)
	{
		otro_aux /= 16;
		i++;
	}
	res = (char *) malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return NULL;
	temp = (char *) malloc(sizeof(char) * (i + 1));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (num != 0)
	{
		aux = num % 16;
		if (aux < 10)
			aux += 48;
		else
			aux += 87;
		temp[i++] = aux;
		num /= 16;
	}
	j = 0;
	while(--i > -1)
		res[j++] = temp[i];
	res[j] = 0;
	return res;
}

void	ft_toupper(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
}

int	put_hex(unsigned int num, int fd, int style)
{
	char	*str;
	str = parseToHex(num);
	if (style == 1) // 0 => es minuscula
		ft_toupper(str);
	ft_putstr_fd(str, fd);
	return ft_strlen(str);
}

int	check(va_list params, char const *str, int i)
{
	int printed_chars;

	printed_chars = 0;
	if (str[i] == 'c')
		printed_chars += ft_putchar_fd(va_arg(params, int),1);
	else if (str[i] == 's')
	 	printed_chars += ft_putstr_fd(va_arg(params, char *),1);
	else if (str[i] == 'p')		//TODO: como coño imprimir una dirección
		ft_putchar_fd('%',1);
	else if (str[i] == 'd')		//TODO: llamar a putnbr
		ft_putchar_fd('%',1);
	else if (str[i] == 'i')		//TODO: llamar a putnbr?
		ft_putchar_fd('%',1);
	else if (str[i] == 'u')		//TODO: cambiar algo en putnbr?
		ft_putchar_fd('%',1);
	else if (str[i] == 'x')		
		printed_chars += put_hex(va_arg(params, unsigned int),1,0);
	else if (str[i] == 'X')		
		printed_chars += put_hex(va_arg(params, unsigned int),1,1);
	else if (str[i] == '%')
		printed_chars += ft_putchar_fd('%',1);	
	return printed_chars;
}

int ft_printf(char const *str, ...)
{
	int		res;
	int		i;
	va_list	params;

	i = -1;
	res = 0;    
	va_start(params, str);
	while(str[++i] != '\0')
	{
		if(str[i] == '%')
			res += check(params, str,++i);
		else
			res += ft_putchar_fd(str[i],1);
	}
	va_end(params);
	return (res);
}





int main()
{
	//! CARÁCTERES
	printf("CARÁCTERES\n");
	int n_ft = ft_printf("%c %c %c %c", 'H','O','L','A'); printf(" | Carácteres FT: %d\n",n_ft);
	int n = printf("%c %c %c %c", 'H','O','L','A'); printf(" | Carácteres: %d\n",n);
	n_ft = ft_printf("%c", 126); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%c", 126); printf(" | Carácteres: %d\n",n);
	
	//! STRINGS
	printf("---------------------------\n");
	printf("STRINGS\n");
	char str[5] = "hola";
	char *ptr = str;
	n_ft = ft_printf("%s",ptr); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%s",ptr); printf(" | Carácteres: %d\n",n);
	
	ptr = NULL;
	n_ft = ft_printf("%s",ptr); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%s",ptr); printf(" | Carácteres: %d\n",n);

	//! HEXADECIMALES
	printf("---------------------------\n");
	printf("HEXADECIMALES\n");
	unsigned int hex = 4294967295;
	n_ft = ft_printf("x: %x | X: %X",hex,hex); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("x: %x | X: %X",hex,hex); printf(" | Carácteres: %d\n",n);
	return 0;
}
//0x16f84b320