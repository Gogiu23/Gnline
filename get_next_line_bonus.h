#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
#endif

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char	*get_next_line_bonus(int fd);

#endif
