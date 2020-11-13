/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgwyneth <fgwyneth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:33:59 by fgwyneth          #+#    #+#             */
/*   Updated: 2020/10/02 23:21:14 by fgwyneth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*new_str;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(new_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
												   ft_strlen(s2) + 2))))
		return (NULL);
	while (s1[j])
		new_str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}

int		ft_strlen(const char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strrchr(char *str, char ch)
{
	int		i;

	i = ft_strlen(str) + 1;
	while (i--)
	{
		if (str[i] == ch)
			return (str + i);
	}
	return (NULL);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new_str;
	size_t		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(new_str = (char *)malloc(sizeof(char) * (len + 10))))
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (new_str);
	while (s[start] && i < len)
	{
		new_str[i] = s[start];
		start++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
