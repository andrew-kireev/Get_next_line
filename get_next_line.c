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
#include <stdlib.h>
#include <unistd.h>

void		clear_buffer(char *str, size_t size)
{
	size_t		i;

	i = 0;
	while (i != size)
	{
		str[i] = '\0';
		i++;
	}
}

int			read_file(int fd, char **lines_fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*tmp;
	int			result;

	result = 0;
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
		if (ft_strrchr(lines_fd[fd], '\n') != NULL)
			return (result);
		clear_buffer(buf, BUFFER_SIZE + 1);
	}
	if (bytes_read == -1)
		result = -1;
	return (result);
}

int			check_line(char *line)
{
	char	*ptr;

	if (line == NULL)
		return (-1);
	if ((ptr = ft_strrchr(line, '\n')) != NULL)
	{
		*ptr = '\0';
		return (1);
	}
	return (0);
}

char		*clear_lines(char **lines_fd, int start, int fd)
{
	char *tmp;

	if (lines_fd[fd][start] == '\n' && ft_strlen(lines_fd[fd]) > start)
		start++;
	tmp = ft_strdup(&(lines_fd[fd][start]));
	free(lines_fd[fd]);
	lines_fd[fd] = tmp;
	return (tmp);
}

int			get_next_line(int fd, char **line)
{
	static char	*lines_fd[FD_NUMS];
	int			reading_result;
	int			return_value;
	int			end;

	return_value = 0;
	end = 0;
	if ((fd < 0 || !line || BUFFER_SIZE == 0) != 0)
		return (-1);
	reading_result = read_file(fd, lines_fd);
	if (reading_result >= 0)
	{
		while (lines_fd[fd][end] != '\0' && lines_fd[fd][end] != '\n')
			end++;
		*line = ft_substr(lines_fd[fd], 0, end + 1);
		return_value = check_line(*line);
		clear_lines(lines_fd, ft_strlen(*line), fd);
	}
	if (reading_result == -1)
		return_value = -1;
	return (return_value);
}
