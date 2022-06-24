-include sources.mk
-include includes.mk
-include sourcesbonus.mk
-include includesbonus.mk

INCLUDE_PATH	= ./includes

OBJS 			= $(SOURCES:.c=.o)

OBSBONUS		= $(SOURCESBONUS:.c=.o)

CC 				= gcc
CFLAGS 			:= -Wall -Wextra -Werror -D BUFFER_SIZE=5
DEPS			= get_next_line.h
DEPSBONUS		= get_next_line_bonus.h
RM	 			= rm -f

line:	$(OBJS) $(DEPS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

bonus:	$(OBSBONUS) $(DEPSBONUS)
	$(CC) -o $@ $(OBSBONUS) $(CFLAGS) 

make: 
	./line

clean:	
	@rm -f ./line a.out
	@echo todo limpio!!

fclean: clean
	@rm -f make
	@rm -f $(OBJS) $(OBSBONUS)
	@echo limpiado el ejecutable

re: fclean all

gmk:
	@find . -name '*.c' | sed 's/^/SOURCES += /' > sources.mk
	@find . -name '*.h' | sed 's/^/INCLUDES += /' > includes.mk
	@find . -name '*bonus.c' | sed 's/^/SOURCESBONUS += /' > sourcesbonus.mk
	@find . -name '*bonus.h' | sed 's/^/INCLUDES += /' > includesbonus.mk

export:
	@./scripts/export2.sh
	@printf "$(BLUE)$(NAME): $(YELLOW)Get next line exported.\n$(RESET)"

end:
	@make fclean
	@make gmk
	@make export
	@printf "\033[1:32m$(NAME): $(LIGHT_CYAN)Todo listo. Te falta solo la norminette vecio!\n$(RESET)"

.PHONY: clean fclean all make gmk export end bonus
