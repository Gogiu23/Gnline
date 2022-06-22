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

char	*new_ptr(char *ptr)
{
	char	*up_ptr;
	int		pos;

	pos = 0;
	while (ptr[pos] != '\n')
		pos++;
	up_ptr = ft_substr(ptr, pos + 1, ft_strlen_next(ptr));
	return (up_ptr);
}

char	*get_line(char *ptr)
{
	char	*line;
	int		count;

	count = 0;
	if (!ptr[count])
		return (NULL);
	while (ptr[count] && ptr[count] != '\n')
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
	line[count] = '\n';
	line[count + 1] = '\0';
	return (line);
}

char	*ft_read_line(int fd, char *ptr)
{
	char	*buffer;
	int		nbytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	if (!ptr)
	{
		ptr = (char *)malloc(sizeof(char) + 1);
		ptr[0] = '\0';
	}
	while (!ft_strchr(ptr, '\n') && nbytes != 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nbytes] = '\0';
		ptr = ft_strjoin(ptr, buffer);
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
	line = get_line(ptr);
	ptr = new_ptr(ptr);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char  *final_line;
	int  pf;	//Flujo
	int	  i;
	//Abrimos el fichero

	i = 1;
	pf = open("fd1.txt", O_RDONLY); //w = write; t = fichero de texto
	//escribimos en el fichero

	//	dprintf(pf, "Hola mundo!\n");
	//	dprintf(pf, "%d * %d = %d\n", 9, 256, 9 * 256);
	//cerramos el fichero
	while (i <= 9)
	{	
		final_line = get_next_line(pf);
		printf("\n\033[0;36m La primera linia: %02d, %s\033[0m\n", i, final_line);
		i++;
		free(final_line);
	}
	close(pf);
	return (0);
}
