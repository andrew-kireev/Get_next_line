#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"


int main(void)
{
    int fd = open("/Users/andrewkireev/Documents/GitHub/GNL/Get_next_line/text", O_RDONLY);
    // int fd2 = open("/Users/andrewkireev/Documents/GitHub/GNL/Get_next_line/test2", O_RDONLY);
    printf("fd = %d\n", fd);
    char    *str = (char *) malloc(sizeof(char *));
    int bytes_read;
    while (1)
    {
         bytes_read = get_next_line(fd, &str);
         if (bytes_read <= 0)
            return 0;
        printf("%s\n", str);
    }
}
