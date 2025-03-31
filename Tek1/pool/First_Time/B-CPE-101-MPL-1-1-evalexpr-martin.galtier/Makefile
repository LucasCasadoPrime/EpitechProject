##
## EPITECH PROJECT, 2020
## libmy
## File description:
## makefile
##

CC	 = gcc
CFLAGS	= -W -Wall -Wextra
CPPFLAGS	= -Iinclude

SRC        = $(wildcard lib/my/*.c)
OBJ        = $(SRC:.c=.o)
LIB        = lib/libmy.a
TARGET	   = eval_expr

all:	$(TARGET)
	cp lib/my/my.h include

$(TARGET): main.o $(LIB)
	$(CC) main.o -L./lib -lmy -o $@

$(LIB): $(OBJ)
	$(AR) rsc $@ $(OBJ)

clean:
	$(RM) main.o
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) #*#

fclean:	clean
	$(RM) $(LIB)
	$(RM) $(TARGET)
	$(RM) include/my.h
	$(RM) lib/my/libmy.a

re:	fclean all
