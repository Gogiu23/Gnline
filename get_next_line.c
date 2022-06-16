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
	int	  pos;

	pos = 0;
	printf("  VALOR DE PTR ANTES DE SUBSTR: %s", ptr);
	while (ptr[pos] != '\n')
		pos++;
	up_ptr = ft_substr(ptr, pos + 1, ft_strlen_next(ptr));
//	up_ptr = ft_strtrim(ft_strchr(ptr, '\n'), ptr);
	return (up_ptr);
}

char	*get_line(char *ptr)
{
	char  *line;
	int	  count;

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
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	char			*buffer;
	int				nbytes;
	static char		*ptr;
	int				i;
	
	printf("valor de PTR: %s", ptr);
	i = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	if (!ptr)
	{
		ptr = (char *)malloc(sizeof(char));
		ptr[0] = '\0';
	}
	printf("\n\033[1;32m-------------------ENTRAMOS EN EL WHILE---------------------\033[0m\n");
	while (!ft_strchr(ptr, '\n'))
	{
		printf("\nValor de buffer antes del read: %s\n", buffer);
		printf("Valor de nbytes antes del read: %d\n", nbytes);
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == 0)
			break ;
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
	printf("'\033[1;91m'--------------------------NOS VAMOS A OTRA FUNCION-----------------\033[0m\n");
	free(buffer);
	line = get_line(ptr);
	printf("\033[1;34m\n---------------NOS VAMOS A LA ULTIMA FUNCION SUBSTR----------------\033[0m\n");
	ptr = new_ptr(ptr);
	printf("VALOR DEVUELTO DE PTR: %s", ptr);
	printf("\n\033[1;36m-------------------------VAMOS A VER QUE HA DEVUELTO NUESTRA GET NEXT LINE----------------------\033[0m\n");
	return (line);
}
