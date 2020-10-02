/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgwyneth <fgwyneth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:33:24 by fgwyneth          #+#    #+#             */
/*   Updated: 2020/10/02 11:39:14 by fgwyneth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int  process_line(char *line_fd, char **line)
{
//     printf("3%c", '\n');
    *line = sub_str(line_fd);
    return (1);
}

int  read_file(int fd, char **lines_fd)
{
    char        buf[BUF_SIZE];
    char        *str;
    int         result;
    int         bytes_read;

    bytes_read = 0;
    while ((bytes_read = read(fd, buf, BUF_SIZE)))
    {
//        printf("bytes = %d", bytes_read);
        if (bytes_read <= 0)
        {
            return (-1);
        }
        buf[bytes_read] = '\0';
        if (lines_fd[fd] != NULL)
            str = ft_strjoin(lines_fd[fd], buf);
        else
            str = buf;
        printf("2%c", '\n');
        lines_fd[fd] = str;
        if (find_end(lines_fd[fd]))
            return (1);
    }
    return (0);
}

int         get_next_line(int fd, char **line)
{
    static char *lines_fd[FD_NUMS];
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
    return (1);
}