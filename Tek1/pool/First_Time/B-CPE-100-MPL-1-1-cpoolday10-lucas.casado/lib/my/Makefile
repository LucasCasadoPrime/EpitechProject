##
## EPITECH PROJECT, 2020
## lib
## File description:
## make
##

CC = gcc

CFLAGS = -W -Wall -Werror -Wextra -g

CPPFLAGS  = -Iinclude

SRC =	lib/my/*.c

OBJ =	$(SRC:.c=.o)

INCLUDE = ../../include/ 

LIB =	lib/my/libmy.a

all: 	$(LIB)
	echo "done"

$(LIB):	$(OBJ)
	$(AR) rsc $@ $(OBJ)

clean:	$(RM) main.o
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) #*#
	cp my.h $(INCLUDE)/my.h

fclean:	clean
	$(RM) $(LIB)

re:	fclean all 
