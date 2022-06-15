#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char	*get_next_line(int pf);

int	main()
{
	int  pf;	//Flujo
	int	  i;
	//Abrimos el fichero

	i = 0;
	pf = open("fd1.txt", O_RDONLY); //w = write; t = fichero de texto
	//escribimos en el fichero

//	dprintf(pf, "Hola mundo!\n");
//	dprintf(pf, "%d * %d = %d\n", 9, 256, 9 * 256);
	//cerramos el fichero
	printf("EL FD DEVUELTO DEL GET NEXT LINE: %s", get_next_line(pf));
	printf("El valor de pf es: %d\n", pf);
	close(pf);
	return (0);
}
