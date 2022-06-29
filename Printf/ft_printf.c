/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:53:41 by guvargas          #+#    #+#             */
/*   Updated: 2022/06/29 16:02:59 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(va_list params, char const *str, int i)
{
	int printed_chars;

	printed_chars = 0;
	if (str[i] == 'c')
		printed_chars += put_char(va_arg(params, int));
	else if (str[i] == 's')
	 	printed_chars += put_str(va_arg(params, char *));
	else if (str[i] == 'p')		//TODO: como coño imprimir una dirección
		printed_chars += put_hex((unsigned long int)va_arg(params, void *),2);
	else if (str[i] == 'd' || str[i] == 'i')
		printed_chars += put_num(va_arg(params, int));
	else if (str[i] == 'u')		//TODO: falla cuando se pasa el limite
		printed_chars += put_u_num(va_arg(params, unsigned int));
	else if (str[i] == 'x')		
		printed_chars += put_hex(va_arg(params, unsigned int),0);
	else if (str[i] == 'X')		
		printed_chars += put_hex(va_arg(params, unsigned int),1);
	else if (str[i] == '%')
		printed_chars += put_char('%');	
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
			res += put_char(str[i]);
	}
	va_end(params);
	return (res);
}





// int main()
// {
// 	//! CARÁCTERES
// 	printf("---------------------------\n");
// 	printf("CARÁCTERES\n");
// 	int n_ft = ft_printf("%c %c %c %c", 'H','O','L','A'); printf(" | Carácteres FT: %d\n",n_ft);
// 	int n = printf("%c %c %c %c", 'H','O','L','A'); printf(" | Carácteres: %d\n",n);
// 	n_ft = ft_printf("%c", 126); printf(" | Carácteres FT: %d\n",n_ft);
// 	n = printf("%c", 126); printf(" | Carácteres: %d\n",n);
// 	n_ft = ft_printf("%c %c %c", '0',0,'1'); printf(" | Carácteres FT: %d\n",n_ft);
// 	n = printf("%c %c %c", '0',0,'1'); printf(" | Carácteres: %d\n",n);

	
// 	//! STRINGS
// 	printf("---------------------------\n");
// 	printf("STRINGS\n");
// 	char str[5] = "hola";
// 	char *ptr = str;
// 	n_ft = ft_printf("%s",ptr); printf(" | Carácteres FT: %d\n",n_ft);
// 	n = printf("%s",ptr); printf(" | Carácteres: %d\n",n);
	
// 	ptr = NULL;
// 	n_ft = ft_printf("%s",ptr); printf(" | Carácteres FT: %d\n",n_ft);
// 	n = printf("%s",ptr); printf(" | Carácteres: %d\n",n);

// 	//! PUNTEROS
// 	printf("---------------------------\n");
// 	printf("PUNTEROS\n");
// 	char *my_ptr = NULL;
// 	n_ft = ft_printf("%p",my_ptr); printf(" | Carácteres FT: %d\n",n_ft);
// 	n = printf("%p",my_ptr); printf(" | Carácteres: %d\n",n);

// 	my_ptr = str;
// 	n_ft = ft_printf("%p",my_ptr); printf(" | Carácteres FT: %d\n",n_ft);
// 	n = printf("%p",my_ptr); printf(" | Carácteres: %d\n",n);
	
// 	//! DECIMALES CON SIGNO
// 	printf("---------------------------\n");
// 	printf("DECIMALES CON SIGNO\n");
// 	n_ft = ft_printf("%d",2147483647); printf(" | Carácteres FT: %d\n",n_ft);
// 	n = printf("%d",2147483647); printf(" | Carácteres: %d\n",n);
	
// 	//! DECIMALES SIN SIGNO
// 	printf("---------------------------\n");
// 	printf("DECIMALES SIN SIGNO\n");
// 	n_ft = ft_printf("%u",-2147483647); printf(" | Carácteres FT: %d\n",n_ft);
// 	n = printf("%u",-2147483647); printf(" | Carácteres: %d\n",n);

// 	//! ENTEROS
// 	printf("---------------------------\n");
// 	printf("ENTEROS\n");
// 	n_ft = ft_printf("%i",-2147483647); printf(" | Carácteres FT: %d\n",n_ft);
// 	n = printf("%i",-2147483647); printf(" | Carácteres: %d\n",n);

// 	//! HEXADECIMALES
// 	printf("---------------------------\n");
// 	printf("HEXADECIMALES\n");
// 	unsigned int hex = 0;
// 	n_ft = ft_printf("x: %x | X: %X",hex,hex); printf(" | Carácteres FT: %d\n",n_ft);
// 	n = printf("x: %x | X: %X",hex,hex); printf(" | Carácteres: %d\n",n);
// 	return 0;
// }
