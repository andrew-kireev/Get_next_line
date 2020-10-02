#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"


int main(void)
{
    // int fd = open("/Users/andrewkireev/Documents/GitHub/GNL/GNL_lover/test_files_GNL/test_file13", O_RDONLY);
    int fd = open("/Users/andrewkireev/Documents/GitHub/GNL/Get_next_line/text", O_RDONLY);
    char    *str = (char *)malloc(sizeof(char *));
    int bytes_read;
    int count = 0;
    while (1)
    {
         bytes_read = get_next_line(fd, &str);
         if (bytes_read <= 0)
            break;
        printf("%s\n", str);
        count++;
    }
}
