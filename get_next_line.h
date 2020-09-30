/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgwyneth <fgwyneth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:34:01 by fgwyneth          #+#    #+#             */
/*   Updated: 2020/10/01 00:53:55 by fgwyneth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>

# define FD_NUMS 512

int         get_next_line(int fd, char **line);
char        *ft_strjoin(char const *s1, char const *s2);
char	    *ft_strdup(const char *str);
void        ft_str_clear(char *str);
int         find_end(char *str);
int		    ft_strlen(const char *str);
static int  process_line(char *line_fd, char **line);
static int  read_file(int fd, char **lines_fd);
char        *sub_str(char *str);



#endif