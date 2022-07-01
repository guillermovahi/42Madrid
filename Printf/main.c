#include "ft_printf.h"

int main()
{
	//! CARÁCTERES
	printf("---------------------------\n");
	printf("CARÁCTERES\n");
	int n_ft = ft_printf("%c %c %c %c", 'H','O','L','A'); printf(" | Carácteres FT: %d\n",n_ft);
	int n = printf("%c %c %c %c", 'H','O','L','A'); printf(" | Carácteres: %d\n",n);
	n_ft = ft_printf("%c", 126); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%c", 126); printf(" | Carácteres: %d\n",n);
	n_ft = ft_printf("%c %c %c", '0',0,'1'); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%c %c %c", '0',0,'1'); printf(" | Carácteres: %d\n",n);

	
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
	
	hex = 9841678;
	n_ft = ft_printf("x: %x | X: %X",hex,hex); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("x: %x | X: %X",hex,hex); printf(" | Carácteres: %d\n",n);
	return 0;
}
