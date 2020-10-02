/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgwyneth <fgwyneth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:33:24 by fgwyneth          #+#    #+#             */
/*   Updated: 2020/10/02 14:25:11 by fgwyneth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int  process_line(char *line_fd, char *line[FD_NUMS])
{
//     printf("3%c", '\n');
    *line = sub_str(line_fd);
    return (1);
}

int  read_file(int fd, char **lines_fd)
{
    char        buf[BUFSIZ + 1];
    char        *str;
    int         result;
    int         bytes_read;

    bytes_read = 0;
	if (lines_fd[fd] == NULL)
		lines_fd[fd] = ft_strdup("");
    while ((bytes_read = read(fd, buf, BUFSIZ)))
    {
//        printf("bytes = %d", bytes_read);
        buf[bytes_read] = '\0';
		lines_fd[fd] = ft_strjoin(lines_fd[fd], buf);
        if (find_end(lines_fd[fd]) > 0)
            return (bytes_read);
    }
    return (bytes_read);
}

int         get_next_line(int fd, char **line)
{
	static char *lines_fd[100];
    int         reading_result;
    
    reading_result = 0;
    if (fd < 0 || !line)
    {
        printf("20%c", '\n');
        return (-1);
    }
//    printf("1%c", '\n');
//
//     printf("5%c", '\n');
    reading_result = read_file(fd, lines_fd);
    if (reading_result != 0 || lines_fd[fd] != NULL)
        process_line(lines_fd[fd], line);
	lines_fd[fd] = remove_str(lines_fd[fd]);
    return (reading_result);
}