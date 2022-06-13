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

char	*get_next_line(int fd)
{
	char			*buffer;
	int				nbytes;
	static char		*ptr;
	int				i;

	i = 0;
	nbytes = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while (!(ft_strchr(buffer, '\n')) || )
	{
		printf("Valor de buffer antes del read: %s\n", buffer);
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == 0)
			return (NULL);
		ptr = ft_strjoin(ptr, buffer);
		i++;
		printf("Contenido de ptr dentro del while: %s\n", ptr);
		printf("Vueltas dentro del while: %d\n", i);
	}
	free(buffer);
	return (ptr);
}
