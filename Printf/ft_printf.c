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

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;
	int				res;

	res = 0;
	if (n < 0)
	{
		res += ft_putchar_fd('-', fd);
		number = -n;
	}
	else
		number = n;
	if (number > 9)
	{
		res += ft_putnbr_fd(number / 10, fd);
		number %= 10;
	}
	res += ft_putchar_fd(number + '0', fd);
	return (res);
}

int	ft_putunbr_fd(int n, int fd)
{
	int				res;
	//unsigned int	number;
	res = 0;

	if (n < 0)
		n = -n;

	if (n > 9)
	{
		res += ft_putunbr_fd(n / 10, fd);
		n %= 10;
	}
	res += ft_putchar_fd(n + '0', fd);
	return (res);
}

char	*invert_string(char *str, int size)
{
	char	*res;
	int		j;

	j = 0;
	res = (char *) malloc(sizeof(char) * (size + 1) );
	if (res == NULL)
		return (NULL);
	while (--size > -1)
		res[j++] = str[size];
	res[j] = 0;
	return (res);
}

int	get_hex_length(unsigned int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

char	*parse_to_hex(unsigned int num)
{
	char			*res;
	unsigned int	aux;
	int				i;

	if (num == 0)
		return ("0");

	i = get_hex_length(num);
	res = (char *) malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return NULL;
	i = 0;
	while (num != 0)
	{
		aux = num % 16;
		if (aux < 10)
			aux += 48;
		else
			aux += 87;
		res[i++] = aux;
		num /= 16;
	}
	return invert_string(res, i);
}

void	to_upper(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
}

int	put_hex(unsigned int num, int style)
{
	char	*str;
	int		size;

	size = 0;
	if (style == 2)
		size += ft_putstr_fd("0x", 2);
	str = parse_to_hex(num);
	if (style == 1)
		to_upper(str);
	size += ft_putstr_fd(str, 1);
	return (size);
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
		printed_chars += put_hex((unsigned long int)va_arg(params, void *),2);
	else if (str[i] == 'd' || str[i] == 'i')
		printed_chars += ft_putnbr_fd(va_arg(params, int),1);
	else if (str[i] == 'u')		//TODO: falla cuando se pasa el limite
		printed_chars += ft_putunbr_fd(va_arg(params, unsigned int),1);
	else if (str[i] == 'x')		
		printed_chars += put_hex(va_arg(params, unsigned int),0);
	else if (str[i] == 'X')		
		printed_chars += put_hex(va_arg(params, unsigned int),1);
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
	printf("---------------------------\n");
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

	//! PUNTEROS
	printf("---------------------------\n");
	printf("PUNTEROS\n");
	char *my_ptr = NULL;
	n_ft = ft_printf("%p",my_ptr); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%p",my_ptr); printf(" | Carácteres: %d\n",n);

	my_ptr = str;
	n_ft = ft_printf("%p",my_ptr); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%p",my_ptr); printf(" | Carácteres: %d\n",n);
	
	//! DECIMALES CON SIGNO
	printf("---------------------------\n");
	printf("DECIMALES CON SIGNO\n");
	n_ft = ft_printf("%d",2147483647); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%d",2147483647); printf(" | Carácteres: %d\n",n);
	
	//! DECIMALES SIN SIGNO
	printf("---------------------------\n");
	printf("DECIMALES SIN SIGNO\n");
	n_ft = ft_printf("%u",-2147483647); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%u",-2147483647); printf(" | Carácteres: %d\n",n);

	//! ENTEROS
	printf("---------------------------\n");
	printf("ENTEROS\n");
	n_ft = ft_printf("%i",-2147483647); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%i",-2147483647); printf(" | Carácteres: %d\n",n);

	//! HEXADECIMALES
	printf("---------------------------\n");
	printf("HEXADECIMALES\n");
	unsigned int hex = 0;
	n_ft = ft_printf("x: %x | X: %X",hex,hex); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("x: %x | X: %X",hex,hex); printf(" | Carácteres: %d\n",n);
	return 0;
}
