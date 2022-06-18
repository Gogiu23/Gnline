/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:34:17 by gdominic          #+#    #+#             */
/*   Updated: 2022/06/11 19:35:51 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen_next(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && (char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*d;
	size_t	i;
	size_t	dest;

	dest = ft_strlen_next(s1) + ft_strlen_next(s2);
	i = 0;
	d = (char *)malloc((dest + 1) * sizeof(char));
	if (!d)
		return (NULL);
	while (i < ft_strlen_next(s1))
	{
		d[i] = s1[i];
		i++;
	}
	while (i < dest)
	{
		d[i] = *s2;
		i++;
		s2++;
	}
	d[i] = '\0';
	free(s1);
	return (d);
}

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	unsigned int		i;
	unsigned int		j;
	char	*str;
	
	i = 0;
	j = 0;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	free(s);
	return (str);
}
