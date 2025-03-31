##
## EPITECH PROJECT, 2022
## B-OOP-400-MPL-4-1-arcade-lucas.casado
## File description:
## Makefile
##

all: $(OBJ)
	make -C ./nibbler
	make -C ./pacman
	make -C ./menu

clean:
	make clean -C ./nibbler
	make clean -C ./pacman
	make clean -C ./menu

fclean: clean
	make fclean -C ./nibbler
	make fclean -C ./pacman
	make fclean -C ./menu

re: fclean all