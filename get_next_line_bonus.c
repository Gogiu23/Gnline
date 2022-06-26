#include "get_next_line_bonus.h"

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
			return (NULL);
		}
		printf("valor de nbytes: %d\n", nbytes);
		printf("contenido de buffer despues del read: %s\n", buffer);
		buffer[nbytes] = '\0';
		ptr = ft_strjoin(ptr, buffer);
	}
	free(buffer);
	printf("Valor de ptr despues de join: %s\n", ptr);
	return (ptr);
}

char	*get_next_line_bonus(int fd)
{
	static char		*ptr;

	ptr = (char *)malloc(1027 * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr = ft_read_line(ptr, fd);
	return (ptr);
}

int main()
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*line;
	char	*line2;
	char	*line3;

	fd = open("bonus.txt", O_CREAT | O_RDWR | O_RDONLY);
//	dprintf(fd, "Hola\n\n\nMe llamo Giuli");
	fd2 = open("bonus2.txt", O_CREAT | O_RDWR | O_RDONLY);
//	dprintf(fd2, "Adios\n");
	fd3 = open("bonus3.txt", O_CREAT | O_RDWR | O_RDONLY);
//	dprintf(fd3, "C'era una volta un giovane intreprendente\nche voleva a tutti i costi diventare principe di Idalgo");
	line = get_next_line_bonus(fd);
	printf("\033[1;33mla primera linia devuelta del primer fichero: \033[0m%s\n", line);
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
}

