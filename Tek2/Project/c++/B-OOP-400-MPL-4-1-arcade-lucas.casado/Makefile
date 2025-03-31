##
## EPITECH PROJECT, 2022
## Rush 03
## File description:
## Makefile
##

BIN 		= arcade

SRC 		= $(wildcard src/*.cpp)
OBJS 		= $(SRC:.cpp=.o)

CPPFLAGS 	= -W -Wall -Wextra -I ./includes -fno-gnu-unique -g3

LDLIBS		= -ldl 

all: core games graphicals

core:	$(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(BIN) $(LDLIBS)
	@echo "\033[1;32mCore compilated!\033[1;0"

games:
	make -C ./lib/games
	@echo "\033[1;32mGames compilated!\033[1;0"

graphicals:
	make -C ./lib/graphicals
	@echo "\033[1;32mGraphic libraries compilated!\033[1;0"

clean:
	$(RM) $(OBJS) $(TESTS_OBJS) *.gcno *gcda
	make -C ./lib/games
	make -C ./lib/graphicals

fclean: clean
	$(RM) $(BIN) $(TESTS_BIN)
	make fclean -C ./lib/games
	make fclean -C ./lib/graphicals

re: fclean all

.PHONY: all core games graphicals clean fclean re
