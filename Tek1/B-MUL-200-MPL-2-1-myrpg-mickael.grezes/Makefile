##
## EPITECH PROJECT, 2020
## makefile
## File description:
## compile libmy
##

CC	= gcc

SRC	= $(wildcard src/*.c)

OBJ	= $(SRC:.c=.o)

NAME	= my_rpg

CFLAGS	= -Wall -Wextra -I./lib/my -I./include -L./lib/ -lmy -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -g3

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my

re: fclean all

.PHONY: all clean fclean re
