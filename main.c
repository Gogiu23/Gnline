#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char	*get_next_line(int pf);

int	main()
{
	int  pf;	//Flujo

	//Abrimos el fichero

	pf = open("mifichero-t.txt", O_RDWR); //w = write; t = fichero de texto
	//escribimos en el fichero

	dprintf(pf, "Hola mundo!\n");
	dprintf(pf, "%d * %d = %d\n", 9, 256, 9 * 256);

	printf("Lo que hay dentro de pf: %s\n", get_next_line(pf));
	//cerramos el fichero
	
	close(pf);

	return (0);
}
