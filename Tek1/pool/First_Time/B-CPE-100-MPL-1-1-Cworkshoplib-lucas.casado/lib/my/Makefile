##
## EPITECH PROJECT, 2020
## Day10
## File description:
## Makefile
##

CC	= gcc

SRC	= $(wildcard *.c)

OBJ	= $(SRC:.c=.o)

NAME	= libmy.a

CFLAGS	= -W -Wall -Wextra -I../../include

all: $(NAME)
	$(RM) $(OBJ)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp -f $(NAME) ../

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all
