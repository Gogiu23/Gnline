/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:34:05 by gdominic          #+#    #+#             */
/*   Updated: 2022/06/09 18:34:10 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_inout_buff
{
	char	*s_ptr;
	int		s_cnt;
	char	*s_base;
	char	s_flag;
	char	s_file;
	int		s_charbuf;
	int		s_bufsiz;
	char	*s_tmpfname;
}	t_inout_buff;

char	*get_next_line(int fd);

#endif
