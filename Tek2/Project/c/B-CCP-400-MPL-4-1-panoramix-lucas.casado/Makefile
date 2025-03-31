##
## EPITECH PROJECT, 2022
## B-CCP-400-MPL-4-1-panoramix-lucas.casado
## File description:
## Makefile
##

CC	= gcc -g3

SRC	= src/main.c \
	src/villagers.c \
	src/potion.c

NAME	= panoramix

OBJ	=  $(SRC:.c=.o)

FLAGS	= -I./include -lpthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all