#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"


int main(int argc, char **argv)
{
    int fd = open("/Users/andrewkireev/Documents/GitHub/GNL/Get_next_line/text", O_RDONLY);
    printf("fd = %d\n", fd);
    char    *str;
    get_next_line(fd, &str);
    printf("%s\n", str);
}
