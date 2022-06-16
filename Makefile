-include sources.mk
-include includes.mk
INCLUDE_PATH	= ./includes

OBJS 			= $(SOURCES:.c=.o) 

CC 				= gcc
CFLAGS 			:= -Wall -Wextra -Werror -D BUFFER_SIZE=75
DEPS			= get_next_line.h
RM	 			= rm -f

#%.o:	%.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS) -I$(DEPS)
#	touch $@

line:	$(OBJS) $(DEPS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

make: 
	./line

clean:	
	@rm -f ./line a.out
	@echo todo limpio!!

fclean: clean
	@rm -f make
	@rm -f $(OBJS)
	@echo limpiado el ejecutable

re: fclean all

gmk:
	@find . -name '*.c' | sed 's/^/SOURCES += /' > sources.mk
	@find . -name '*.h' | sed 's/^/INCLUDES += /' > includes.mk

export:
	@./scripts/export.sh
	@printf "$(BLUE)$(NAME): $(YELLOW)Get next line exported.\n$(RESET)"

end:
	@make fclean
	@make gmk
	@make export
	@printf "$(BLUE)$(NAME): $(LIGHT_CYAN)Todo listo. Te falta solo la norminette vecio!\n$(RESET)"

.PHONY: clean fclean all make gmk export end
