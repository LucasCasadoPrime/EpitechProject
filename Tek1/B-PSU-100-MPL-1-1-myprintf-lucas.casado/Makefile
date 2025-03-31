##
## EPITECH PROJECT, 2020
## Cworkshoplib Makefile
## File description:
## Makefile of libmy
##

CC      = gcc

SRC     = $(wildcard sources/*.c)

OBJ     = $(SRC:.c=.o)

NAME    = libmy.a

CFLAGS  = -W -Wall -Wextra -I./includes

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

