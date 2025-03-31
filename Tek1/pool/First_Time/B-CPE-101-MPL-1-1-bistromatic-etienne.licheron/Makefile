##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compile bistromatic
##

CC		= gcc

FLAGS	= -W -Wall -Wextra

TARGET 	= *.c

NAME	= calc

all:
	$(CC) $(FLAGS) $(TARGET) -o $(NAME)

clean:
	$(RM) *.c~

fclean: clean
	$(RM) $(NAME)

re: fclean all