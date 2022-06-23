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
	int		i;

	i = 0;
	if (!s[i])
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen_next(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *ptr, char *buffer)
{
	char	*newstr;
	size_t	j;
	size_t	i;
	size_t	dest;

	if (!ptr)
	{
		ptr = (char *)malloc(sizeof(char) * 1);
		ptr[0] = '\0';
	}
	if (!ptr || !buffer)
		return (NULL);
	dest = ft_strlen_next(ptr) + ft_strlen_next(buffer);
	i = -1;
	j = 0;
	newstr = (char *)malloc((dest + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	if (ptr)
		while (ptr[++i] != '\0')
			newstr[i] = ptr[i];
	while (buffer[j] != '\0')
		newstr[i++] = buffer[j++];
	newstr[ft_strlen_next(ptr) + ft_strlen_next(buffer)] = '\0';
	free(ptr);
	return (newstr);
}

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	unsigned int		i;
	unsigned int		j;
	char				*str;

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
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	free(s);
	return (str);
}
