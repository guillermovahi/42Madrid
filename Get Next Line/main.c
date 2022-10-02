#include "get_next_line.h"

int main(){

    char *vamos_a_leer;
    
    int fd = open("file.txt", O_RDONLY); 
/*     vamos_a_leer = get_next_line(fd);
    printf("leido -> %s", vamos_a_leer);
	printf("---------------------------\n");

	vamos_a_leer = get_next_line(fd);
    printf("leido -> %s", vamos_a_leer);
	printf("\n---------------------------\n");

	vamos_a_leer = get_next_line(fd);
    printf("leido -> %s", vamos_a_leer);
	printf("\n---------------------------\n"); */

	int i = 0;

		vamos_a_leer = get_next_line(fd);
    	printf("leido -> %s", vamos_a_leer);
		printf("\n---------------------------\n");
		i++;

	return 0;
}