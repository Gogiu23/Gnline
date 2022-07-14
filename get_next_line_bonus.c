/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:35:52 by gdominic          #+#    #+#             */
/*   Updated: 2022/07/06 20:11:56 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_newptr(char *ptr)
{
	char	*upg_ptr;
	int		count;

	count = 0;
	while (ptr[count] && ptr[count] != '\n')
		count++;
	if (!ptr[count])
	{
		free(ptr);
		return (NULL);
	}
	upg_ptr = ft_substr(ptr, count + 1, ft2_strlen(ptr));
	return (upg_ptr);
}

char	*ft_getlines(char *ptr)
{
	char	*line;
	int		n;

	n = 0;
	if (!ptr[n])
		return (NULL);
	while (ptr[n] && ptr[n] != '\n')
		n++;
	line = (char *)malloc(n * sizeof(char) + 2);
	if (!line)
		return (NULL);
	n = 0;
	while (ptr[n] && ptr[n] != '\n')
	{
		line[n] = ptr[n];
		n++;
	}
	if (ptr[n] == '\n')
	{
		line[n] = '\n';
		n++;
	}
	line[n] = '\0';
	return (line);
}

char	*ft_read_line(char *ptr, int fd)
{
	char	*buffer;
	int		nbytes;

	nbytes = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(ptr, '\n') && nbytes != 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(buffer);
			free(ptr);
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
	static char		*ptr[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	ptr[fd] = ft_read_line(ptr[fd], fd);
	if (!ptr[fd])
		return (NULL);
	line = ft_getlines(ptr[fd]);
	ptr[fd] = ft_newptr(ptr[fd]);
	return (line);
}
/*
int main()
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*line;
	char	*line2;
	char	*line3;

	fd = open("bonus.txt", O_RDONLY);
//	dprintf(fd, "Hola\n\n\nMe llamo Giuli");
	fd2 = open("bonus2.txt", O_RDONLY);
//	dprintf(fd2, "Adios\n");
	fd3 = open("bonus3.txt", O_RDONLY);
	line = get_next_line_bonus(fd);
	free(line);
	line2 = get_next_line_bonus(fd2);
	printf("\033[1;32mPrimera linia del segundo fichero: \033[0m%s\n", line2);
	free(line2);
	line3 = get_next_line_bonus(fd3);
	printf("\033[1;31mla primera lina del tercer fichero: \033[0m%s\n", line3);
	free(line3);
	line = get_next_line_bonus(fd);
	free(line);
	line2 = get_next_line_bonus(fd2);
	printf("\033[1;32mPrimera linia del segundo fichero: \033[0m%s\n", line2);
	free(line2);
	line3 = get_next_line_bonus(fd3);
	printf("\033[1;31mla primera lina del tercer fichero: \033[0m%s\n", line3);
	free(line3);
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}*/
