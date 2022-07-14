/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:36:36 by gdominic          #+#    #+#             */
/*   Updated: 2022/07/06 20:10:41 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *ptr, int n);
size_t	ft2_strlen(char *str);
char	*ft_strjoin(char *ptr, char *buffer);
char	*ft_substr(char *s, unsigned int start, unsigned int len);

#endif
