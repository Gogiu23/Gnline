/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:33:46 by gdominic          #+#    #+#             */
/*   Updated: 2022/06/12 14:53:04 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_line(char *ptr, unsigned int tot)
{
	char  *line;
	
	while (ptr[tot] != '\n' || ptr[tot] == '\0')
	{
		printf("Valor de line: %s\n", line);
		line = ft_strchr(ptr, '\n');
		printf("Valor de line: %s\n", line);
		printf("Valor de ptr: %s\n", ptr);
		tot--;
	}
	printf("Valor de line: %s\n", line);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	char			*buffer;
	int				nbytes;
	static char		*ptr;
	int				i;
	int				tot;

	i = 0;
	nbytes = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	
	while (!(ft_strchr(buffer, '\n') && nbytes == 0))
	{
		printf("Valor de buffer antes del read: %s\n", buffer);
		printf("Valor de nbytes antes del read: %d\n", nbytes);
		nbytes = read(fd, buffer, BUFFER_SIZE);
		ptr = ft_strjoin(ptr, buffer);
		i++;
		printf("Contenido de ptr dentro del while: %s\n", ptr);
		printf("Vueltas dentro del while: %d\n", i);
	}
	tot = i * BUFFER_SIZE;
	printf("valor de tot: %d\n", tot);
	free(buffer);
	line = get_line(ptr, tot);
	return (line);
}
