#include "get_next_line_bonus.h"

char	*get_next_line_bonus(int fd)
{
	char			*buffer;
	static char		*ptr;
	int				nbytes;

	nbytes = 1;
	buffer = (char *)malloc(BUFFFER_SIZE + 1) * sizeof(char);
	if (!buffer)
		return (NULL);
}

int main()
{
	int		fd;
	int		fd2;
	int		fd3;
	char	line;

	fd = open("bonus.txt", O_CREAT | O_RDWR);
	dprintf(fd, "Hola\n\n\nMe llamo Giuli");
	fd2 = open("bonus2.txt", O_CREAT | O_RDWR);
	dprintf(fd2, "Adios\n");
	fd3 = open("bonus3.txt", O_CREAT | O_RDWR);
	dprintf(fd3, "C'era una volta un giovane intreprendente\nche voleva a tutti i costi diventare principe di Idalgo");
	line = get_next_line_bonus(fd);
	printf("%s\n", line);
	free(line);
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}

