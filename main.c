#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"


void clear(char *str)
{
	int i = 0;

	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
}


int main(void)
{
    int fd = open("/Users/andrewkireev/Documents/GitHub/GNL/Get_next_line/text", O_RDONLY);
    int bytes_read = 0;
    int count = 0;
    while (1)
    {
		char    *str = NULL;
         bytes_read = get_next_line(42, &str);
		printf("bytes = %d", bytes_read);
         if (bytes_read != -1)
			 printf("%s\n", str);
         if (bytes_read <= 0) {
//         	if (bytes_read != -1)
			 	free(str);
         	break;
		 }
        count++;
         clear(str);
         free(str);
    }
}
