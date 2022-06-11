/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:33:46 by gdominic          #+#    #+#             */
/*   Updated: 2022/06/09 18:52:34 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	int		nbytes;
	nbytes = 0;
	printf("antes del read: %d\n", nbytes);

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while (buffer[nbytes] <= '\0')
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		nbytes++;
	}
	printf("despues del read: %d\n", nbytes);
	printf("despues del read en int: %s\n", buffer);
	return (buffer);
}
