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

size_t	ft_strlen_n(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *ptr, int n)
{
	int		i;

	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i] != '\0')
	{
		if (ptr[i] == (char)n)
			return (&ptr[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *ptr, char *buffer)
{
	char	*str;
	size_t	j;
	size_t	i;

	if (!ptr)
	{
		ptr = (char *)malloc(sizeof(char) * 1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
	}
	i = -1;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen_n(ptr) + ft_strlen_n(buffer) + 1));
	if (!str)
		return (NULL);
	if (ptr)
		while (ptr[++i] != '\0')
			str[i] = ptr[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen_n(ptr) + ft_strlen_n(buffer)] = '\0';
	free(ptr);
	return (str);
}

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	unsigned int		i;
	unsigned int		j;
	char				*str;

	i = 0;
	j = 0;
	if (!s)
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
