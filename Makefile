OBJS 			= get_next_line.c get_next_line_utils.c main.c

CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror -D BUFFER_SIZE=13
DEPS			= get_next_line.h
RM	 			= rm -f

%.o:	%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

line:	$(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

make: 
	./line

clean:	
	@rm -f ./line a.out
	@echo todo limpio!!

fclean: clean
	@rm -f make
	@echo limpiado el ejecutable

re: fclean all

.PHONY: clean fclean all make
