##
## EPITECH PROJECT, 2020
## B-CPE-110-MPL-1-1-pushswap-lucas.casado
## File description:
## Makefile
##

CC	= gcc

NAME	= push_swap

FLAGS	= source/*.c -I./include -o $(NAME) -g3;

all:
	@ $(CC) $(FLAGS)
	@ echo "\033[1;33mBinary : \033[1;35m$(NAME)\033[1;33m created sucesfully.\033[0m"

clean:
	$(RM) *.o

fclean:
	$(RM) $(NAME)

re: fclean all

unit_tests:
	$(CC) $(UNIT_TEST) $(TEST_FLAGS)