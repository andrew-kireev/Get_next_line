/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgwyneth <fgwyneth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:33:59 by fgwyneth          #+#    #+#             */
/*   Updated: 2020/10/01 00:51:52 by fgwyneth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*new_str;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
	ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[j])
	{
		new_str[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void     ft_str_clear(char *str)
{
    free(str);
    str = NULL;
}

int     find_end(char *str)
{
    int     i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            return (i);
            i++;
    }
    return (-1);
}

char    *sub_str(char *str)
{
    char    *sub_str;
    int     i;

    if (!(sub_str = (char *)malloc(sizeof(char) * find_end(str) + 1)))
        return (NULL);
    i = 0;
    while (str[i] != '\0' && str[i] != '\n')
    {
        sub_str[i] = str[i];
        i++;
    }
    return (sub_str);
}

int		ft_strlen(const char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}