##
## EPITECH PROJECT, 2021
## B-PSU-101-MPL-1-1-bsminishell1-lucas.casado
## File description:
## Makefile
##

CC	= gcc

NAME	= mysh

FLAGS	= source/*.c -I./include -Wall -Wextra -o $(NAME) -g3;

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
