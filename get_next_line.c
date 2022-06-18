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
#include <stddef.h>
#include <string.h>

char	*new_ptr(char *ptr)
{
	char  *up_ptr;
	int	  pos;

	pos = 0;
	printf("  VALOR DE PTR ANTES DE SUBSTR: %s", ptr);
	while (ptr[pos] != '\n')
		pos++;
	printf("VALOR DE POS: %d\n", pos);
	up_ptr = ft_substr(ptr, pos + 1, ft_strlen_next(ptr));
//	free(ptr);
	return (up_ptr);
}

char	*get_line(char *ptr)
{
	char  *line;
	int	  count;
	char  *temp;
	
	temp = 0;
	count = 0;
	if (!ptr[count])
		return (NULL);
	while (ptr[count] && ptr[count] != '\n')
		count++;
	line = (char *)malloc(sizeof(char) * count + 1);
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
//	temp = strdup(line);
//	free(line);
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
		printf("\033[1;31mVALOR DE PTR: %s\n\033[0m", ptr);
		ptr = (char *)malloc(sizeof(char) + 1);
		ptr[0] = '\0';
	}
	nbytes = 1;
	printf("\n\033[1;32m-------------------ENTRAMOS EN EL WHILE---------------------\033[0m\n");
	while (!(ft_strchr(ptr, '\n') && nbytes))
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
		printf("Numero de Nbytes -> : %d\n", nbytes);
		printf("Contenido de ptr dentro del while: %s\n", ptr);
	}
	printf("'\033[1;91m'--------------------------NOS VAMOS A OTRA FUNCION-----------------\033[0m\n");
	free(buffer);
	if (!ptr)
		free(ptr);
	return (ptr);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	ptr = ft_read_line(fd, ptr);
	if (ptr == 0)
	{
		free(ptr);
		return (NULL);
	}
	printf("valor de PTR: %s\n", ptr);
	line = get_line(ptr);
	printf("\033[1;34m\n---------------NOS VAMOS A LA ULTIMA FUNCION SUBSTR----------------\033[0m\n");
	ptr = new_ptr(ptr);
	printf("VALOR DEVUELTO DE PTR: %s", ptr);
	printf("\n\033[1;36m-------------------------VAMOS A VER QUE HA DEVUELTO NUESTRA GET NEXT LINE----------------------\033[0m\n");
	return (line);
}
