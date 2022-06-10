#include <stdio.h>

int	main()
{
	FILE  *pf;	//Flujo
	//Abrimos el fichero

	pf = fopen("mifichero-t.txt", "wt"); //w = write; t = fichero de texto
	//escribimos en el fichero

	fprintf(pf, "Hola mundo!\n");
	fprintf(pf, "%d * %d = %d\n", 9, 256, 9 * 256);
	
	//cerramos el fichero
	
	fclose(pf);

	return (0);
}
