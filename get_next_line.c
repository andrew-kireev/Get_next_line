/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgwyneth <fgwyneth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:33:24 by fgwyneth          #+#    #+#             */
/*   Updated: 2020/10/01 00:54:13 by fgwyneth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int  process_line(char *line_fd, char **line)
{
    *line = sub_str(line_fd);
}

static int  read_file(int fd, char **lines_fd)
{
    char        buf[1024];
    char        *str;
    int         result;
    int         bytes_read;

    while ((bytes_read = read(fd, buf, 1024)))
    {
        if (bytes_read <= 0)
        {
            return (-1);
        }
        buf[bytes_read] = '\0';
        str = ft_strjoin(lines_fd[fd], buf);
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
    
    if (fd < 0 || !line)
        return (-1);
    reading_result = read_file(fd, lines_fd);
    if (reading_result)
        process_line(lines_fd[fd], line);
}