##
## EPITECH PROJECT, 2022
## exemple
## File description:
## Makefile
##

CC    = g++ -g3

SRC    = $(wildcard ./src/*.cpp)

NAME = MyGKrellm

OBJ    =  $(SRC:.cpp=.o)

FLAGS    =  -std=c++2a -Wall -Wextra -Werror -lncurses -lsfml-graphics -lsfml-window -lsfml-system -lncurses

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all