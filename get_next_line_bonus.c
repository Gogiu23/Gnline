#include "get_next_line_bonus.h"

int main()
{
	int fd2;
	int fd;

	fd = open("bonus.txt", O_CREAT);
	close(fd);
	fd = open("bonus.txt", O_RDWR);
	dprintf(3, "Hola\n\n\nMe llamo Giuli");
	close(fd);
	fd2 = open("bonus2.txt", O_CREAT);
	close(fd2);
	fd2 = open("bonus2.txt", O_RDWR);
	dprintf(-1, "Adios\n");
	printf("valor de fd: %d\n", fd);
	printf("Valor de fd2: %d\n", fd2);
	close(fd2);
	return (0);
}

