##
## EPITECH PROJECT, 2020
## B-PSU-100-MPL-1-1-myls-lucas.casado
## File description:
## Makefile
##

FLAG	= ./*c -I./include -L. -lmy -g -o my_ls;

LIB	= sources/*c -I./include -c;

LNAME	= libmy.a

CC	= gcc

AR	= ar

NAME	= my_ls

all:
	@ $(CC) $(LIB)
	@ $(AR) rsc $(LNAME) *.o
	$(RM) *.o
	@ $(CC) $(FLAG)
	@ echo "good job"

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LNAME)

re: fclean all
