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

void clear_buffer(char *str, size_t size)
{
	size_t 		i;

	i = 0;
	while (i != size)
	{
		str[i] = '\0';
		i++;
	}
}

int  read_file(int fd, char **lines_fd)
{
    char        buf[BUFFER_SIZE + 1];
    int         bytes_read;
    char		*tmp;
    int			result;

    result = 0;
    bytes_read = 0;
	if (lines_fd[fd] == NULL)
		lines_fd[fd] = ft_strdup("");
	clear_buffer(buf, BUFFER_SIZE + 1);
    while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
    	result += bytes_read;
    	buf[bytes_read] = '\0';
    	tmp = ft_strjoin(lines_fd[fd], buf);
    	free(lines_fd[fd]);
    	lines_fd[fd] = tmp;
    	if (ft_strrchr(lines_fd[fd], '\n') != NULL) {
    		return result;
    	}
    	clear_buffer(buf, BUFFER_SIZE + 1);
    }
    return (result);
}

int check_line(char *line) {
	char	*ptr;
	int		size;

	size = ft_strlen(line);
	if (line == NULL)
		return (-1);


	if ((ptr = ft_strrchr(line, '\n')) != NULL) {
		*ptr = '\0';
//		if (size != 1)
			return 1;
	}
	return 0;
}

char	*clear_lines(char **lines_fd, int start, int fd) {
	char *tmp;
	if (lines_fd[fd][start] == '\n' && ft_strlen(lines_fd[fd]) > start)
		start++;
	tmp = ft_strdup(&(lines_fd[fd][start]));
	free(lines_fd[fd]);
	lines_fd[fd] = tmp;
	return tmp;
}

int find_end_(const char *str)
{
	int		i;
	if (str == NULL && ft_strlen(str) == 0)
		return 0;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
//	i++;
	return (i);
}

int         get_next_line(int fd, char **line)
{
	static char *lines_fd[100];
    int         reading_result;
    int			return_value;
    if (BUFFER_SIZE <= 0)
    	return (-1);

    return_value = 0;
    reading_result = 0;
    if (fd < 0 || !line)
        return (-1);
    reading_result = read_file(fd, lines_fd);

    if (reading_result >= 0) {
    	*line = ft_substr(lines_fd[fd], 0, find_end_(lines_fd[fd]) + 1);
    	return_value = check_line(*line);
//		printf("%s\n", lines_fd[fd]);
    	lines_fd[fd] = clear_lines(lines_fd, ft_strlen(*line), fd);
//    	printf("%s\n", *line);
    }
    return return_value;
}