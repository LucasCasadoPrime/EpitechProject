##
## EPITECH PROJECT, 2022
## B-OOP-400-MPL-4-1-arcade-lucas.casado
## File description:
## Makefile
##

all: $(OBJ)
	make -C ./ncurses
	make -C ./sdl2
	make -C ./sfml

clean:
	make clean -C ./ncurses
	make clean -C ./sdl2
	make clean -C ./sfml

fclean: clean
	make fclean -C ./ncurses
	make fclean -C ./sdl2
	make fclean -C ./sfml

re: fclean all