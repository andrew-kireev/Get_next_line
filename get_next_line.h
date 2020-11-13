/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgwyneth <fgwyneth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:34:01 by fgwyneth          #+#    #+#             */
/*   Updated: 2020/10/02 23:30:18 by fgwyneth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# define FD_NUMS 512

//# define BUFFER_SIZE 12

int			get_next_line(int fd, char **line);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *str);
int			ft_strlen(const char *str);
int			read_file(int fd, char **lines_fd);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strrchr(char *str, char ch);
char		*clear_lines(char **lines_fd, int start, int fd);
int			check_line(char *line);
void		clear_buffer(char *str, size_t size);

#endif
