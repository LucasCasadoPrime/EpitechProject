##
## EPITECH PROJECT, 2021
## Dante
## File description:
## Makefile
##

CC = gcc

CFLAGS = -W -Wall -Wextra

all:
	@ make -C ./generator
	@ make -C ./solver

clean:
	@ make clean -C ./generator
	@ make clean -C ./solver

fclean:
	@ make fclean -C ./generator
	@ make fclean -C ./solver

re:
	@ make re -C ./generator
	@ make re -C ./solver

tests_run:
	@ make tests_run -C ./generator
	@ make tests_run -C ./solver

coverage:
	@ make coverage -C ./generator
	@ make coverage -C ./solver