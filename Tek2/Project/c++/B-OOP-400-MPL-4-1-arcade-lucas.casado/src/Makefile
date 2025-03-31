##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME    = arcade

SRC    =  main.cpp

CXXFLAGS +=     -W -Wall -Wextra -Wshadow -Werror -ldl -I include

LDLIBS		= -ldl 

OBJ    =    $(SRC:.cpp=.o)

CC    =    g++

all:    $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS)
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)