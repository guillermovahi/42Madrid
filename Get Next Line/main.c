#include "get_next_line.h"


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