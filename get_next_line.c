/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:33:46 by gdominic          #+#    #+#             */
/*   Updated: 2022/07/05 22:46:39 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*new_ptr(char *ptr)
{
	char	*up_ptr;
	int		pos;

	pos = 0;
	while (ptr[pos] && ptr[pos] != '\n')
		pos++;
	if (!ptr[pos])
	{
		free(ptr);
		return (NULL);
	}
	up_ptr = ft_substr(ptr, pos + 1, ft_strlen_n(ptr) + 1);
	return (up_ptr);
}

char	*get_line(char *ptr)
{
	char	*line;
	int		count;

	count = 0;
	if (!ptr[count])
		return (NULL);
	while (ptr[count] != '\n' && ptr[count])
		count++;
	line = (char *)malloc(sizeof(char) * count + 2);
	if (!line)
		return (NULL);
	count = 0;
	while (ptr[count] && ptr[count] != '\n')
	{
		line[count] = ptr[count];
		count++;
	}
	if (ptr[count] == '\n')
	{
		line[count] = '\n';
		count++;
	}
	line[count] = '\0';
	return (line);
}

char	*ft_read_line(int fd, char *ptr)
{
	char	*buffer;
	int		nbytes;
	size_t	i;
	size_t	j;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	nbytes = 1;
	while (!ft_strchr(ptr, '\n') && nbytes != 0)
	{
		i = -1;
		j = 0;
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nbytes] = '\0';
		ptr = ft_strjoin(ptr, buffer, j, i);
	}
	free(buffer);
	return (ptr);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	ptr = ft_read_line(fd, ptr);
	if (!ptr)
		return (NULL);
	line = get_line(ptr);
	ptr = new_ptr(ptr);
	if (!line || !line[0])
		return (0);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char  *final_line;
	int  pf;	//Flujo
	//Abrimos el fichero

	pf = open("files/42_no_nl", O_RDONLY); //w = write; t = fichero de texto
	//escribimos en el fichero

	//	dprintf(pf, "Hola mundo!\n");
	//	dprintf(pf, "%d * %d = %d\n", 9, 256, 9 * 256);
	//cerramos el fichero
	final_line = get_next_line(pf);
	while (final_line)
	{	
		printf("La linia: %s", final_line);
		free(final_line);
		final_line = get_next_line(pf);
	}
	close(pf);
	return (0);
}*/
