#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "get_next_line.h"

char    *get_next_line(int fd)
{

    int i = 0;
    char c;
    char *s = malloc(20);
    
    read(fd, &c, 1);
    s[i++] = c;
    while(c != 0 && c != '\n' )
    {
        
        read(fd, &c, 1);
        //printf("letter: %c\n",c);
        s[i++] = c;
       
    }
    s[i] = '\0';
    return s;
}

int main()
{
    int fd;
    // int i = 0;
    //int sz;
    //char *s = (char *)calloc(100, sizeof(char));

    // char c;
    // char s[20];

    fd = open("file.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("r1");
        exit(1);
    }

    char *str = get_next_line(fd);
    printf("string: %s\n",str);
    str = get_next_line(fd);
    printf("string: %s\n",str);
    // read(fd, &c, 1);
    // while(c != '\n')
    // {
    //     read(fd, &c, 1);
    //     printf("letter: %c\n",c);
    //     s[i] = c;
    //     i++;
    // }
    // s[i] = '\0';
}