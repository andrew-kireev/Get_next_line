/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgwyneth <fgwyneth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:33:24 by fgwyneth          #+#    #+#             */
/*   Updated: 2020/10/02 23:21:27 by fgwyneth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// static int  process_line(char *line_fd, char *line[FD_NUMS])
// {
// //     printf("3%c", '\n');
//     *line = sub_str(line_fd);
//     return (1);
// }

int  read_file(int fd, char **lines_fd)
{
    char        buf[BUFFER_SIZE + 1];
    int         bytes_read;
    int         is_readed;

    bytes_read = 0;
    is_readed = 0;
	if (lines_fd[fd] == NULL)
		lines_fd[fd] = ft_strdup("");
    while ((bytes_read = read(fd, buf, BUFFER_SIZE)))
    {
        if (bytes_read == -1)
            return (-1);
        buf[bytes_read] = '\0';
		lines_fd[fd] = ft_strjoin(lines_fd[fd], buf);
        if (find_end(lines_fd[fd]) > 0)
            return (1);
    }
    return (0);
}

int         get_next_line(int fd, char **line)
{
	static char *lines_fd[100];
    int         reading_result;
    
    reading_result = 0;
    if (fd < 0 || !line)
        return (-1);
    reading_result = read_file(fd, lines_fd);
    if (reading_result != 0 || lines_fd[fd] != NULL)
        *line = sub_str(lines_fd[fd]);
	if (*line == NULL)
		return 0;
	lines_fd[fd] = remove_str(lines_fd[fd]);
    if (reading_result == -1)
        return (-1);
    if (reading_result > 0 || ft_strlen(*line) > 1)
        return (1);
    return(0);
}