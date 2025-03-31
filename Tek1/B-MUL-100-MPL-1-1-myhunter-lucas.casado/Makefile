##
## EPITECH PROJECT, 2020
## B-MUL-100-MPL-1-1-myhunter-lucas.casado
## File description:
## Makefile
##

SRC	= $(wildcard source/*.c)

OBJ	= $(SRC:.c=.o)

CC	= gcc

TARGET	= my_hunter

CFLAGS	= -o $(TARGET) -Werror -Wall -W -Wextra -g3 -I./include-L/usr/local/lib -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -I./include

all: compile

compile:
	rm -f $(TARGET)
	$(CC) $(SRC) $(CFLAGS)

clean:
	$(RM) .o

fclean: clean
	$(RM) $(TARGET)

re: fclean all

