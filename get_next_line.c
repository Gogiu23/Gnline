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
	char  *up_ptr;
	printf("  VALOR DE PTR ANTES DE SUBSTR: %s", ptr);
//	up_ptr = ft_substr(ptr, '\n', ft_strlen_next(ptr));
	up_ptr = ft_strtrim(ft_strchr(ptr, '\n'), ptr);
	return (up_ptr);
}

char	*get_line(char *ptr)
{
	char  *line;
	int	  count;

	count = 0;
	while (ptr[count] && ptr[count] != '\n')
		count++;
	line = (char *)malloc(sizeof(char) * count + 2);
	if (!line)
		return (NULL);
	count = 0;
	printf("  VALOR DE PTR ANTES DE COPIARSE A LINE: %s", ptr);
	printf("\nENTRAMOS EN EL WHILE");
	while (ptr[count] && ptr[count] != '\n')
	{
		line[count] = ptr[count];
		count++;
	}
	printf("\nVALOR DE COUNT (BASICAMENTE CUANTO HEMOS COPIADO): %d\n", count);
	line[count] = '\n';
	line[count + 1] = '\0';
	printf("\nCOPIA HECHA, A VER QUE TENEMOS  -> Valor de line: %s", line);
	printf("\nCOPIA HECHA A VER QUE TENEMOS  -> Valor de ptr: %s", ptr);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	char			*buffer;
	int				nbytes;
	static char		*ptr;
	int				i;

	i = 0;
	nbytes = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	printf("\n-------------------ENTRAMOS EN EL WHILE---------------------\n");	
	while (!ft_strchr(buffer, '\n') && nbytes != 0)
	{
		printf("\nValor de buffer antes del read: %s\n", buffer);
		printf("Valor de nbytes antes del read: %d\n", nbytes);
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		ptr = ft_strjoin(ptr, buffer);
		i++;
		printf("Numero de Nbytes -> : %d\n", nbytes);
		printf("Contenido de ptr dentro del while: %s", ptr);
		printf("Vueltas dentro del while: %d\n", i);
	}
	printf("--------------------------NOS VAMOS A OTRA FUNCION-----------------\n");
	free(buffer);
	line = get_line(ptr);
	printf("\n---------------NOS VAMOS A LA ULTIMA FUNCION SUBSTR-----------------\n");
	ptr = new_ptr(ptr);
	printf("VALOR DEVUELTO DE PTR: %s", ptr);
	printf("\n--------------------------VAMOS A VER QUE HA DEVUELTO NUESTRA GET NEXT LINE---------------------\n");
	return (line);
}
