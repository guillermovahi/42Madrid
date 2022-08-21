#include "get_next_line.h"


<<<<<<< HEAD
=======
void sum5(int num)
{
    static int my_static;
    int my_int = 1;
    printf("my_int: %i\n", my_int);
    printf("my_static: %i\n", my_static);
    my_static += num;
    my_int += num;
}
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
    char    *buff;

	bytes = 0;
	i = -1;
	temp = orig;
    buff = malloc(sizeof(char) * (bf + 1));
    read(fd, buff,bf);
    printf("this is buff %s\n", buff);
    read(fd, buff, bf);
    printf("this is buff %s\n", buff);

	// while(read(fd, &orig, sizeof(orig)) > 0)
	// {
	// 	bytes++;
	// 	// res[i] = c;
	// 	// printf("letter [%d]: %c\n",i,c);        
	// 	if (orig == '\n')
	// 		break;
	// 	//i++;
	// }
	// res = (char *) malloc(sizeof(char) * (bytes + 1));
	// while(++i < bytes)
	// {
	// 	read(fd, &temp, sizeof(temp));
	// 	res[i] = temp;
	// 	// printf("letter [%d]: %c\n",i,c);        
	// 	if (temp == '\n')
	// 		break;
	// 	//i++;
	// }
	res[i] = '\0';
	printf("bytes: %d\n", bytes);
	//s[i] = '\0';
	return res;
}
>>>>>>> dd73891d7b88686399a878732b48640027fcdc35
int main()
{
    int fd;
    fd = open("file.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("r1");
        exit(1);
    }

  
    char *str;
    str = get_next_line(fd);
    printf("string: %s\n",str);
    str = get_next_line(fd);
    printf("string: %s\n",str);
    // str = get_next_line(fd);
    // printf("string: %s\n",str);
    // str = get_next_line(fd);
    // printf("string: %s\n",str);
    // str = get_next_line(fd);
    // printf("string: %s\n",str);
    // str = get_next_line(fd);
    // printf("string: %s\n",str);
    // str = get_next_line(fd);
    // printf("string: %s\n",str);
    // str = get_next_line(fd);
    // printf("string: %s\n",str);
    // str = get_next_line(fd);
    // printf("string: %s\n",str);
    // str = get_next_line(fd);
    // printf("string: %s\n",str);
    // str = get_next_line(fd);
    // printf("string: %s\n",str);
    // str = get_next_line(fd);
    // printf("string: %s\n",str);
}