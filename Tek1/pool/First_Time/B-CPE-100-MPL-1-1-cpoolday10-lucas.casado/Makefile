##
## EPITECH PROJECT, 2020
## libmy.a
## File description:
## Makefile
##

CC 	= gcc

AR 	= ar

RM	= rm


all:
	$(CC) -c *.c
	$(AR) rsc libmy.a *.o
	$(RM) *.o
	cp libmy.a ..libmy.a
	cp my.h ../../inclde/my.h

clean:
	$(RM) *.o
	$(RM) *~
	$(RM) #*#

re:
	$(ALL)
	$(CLEAN)
