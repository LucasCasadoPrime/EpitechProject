##
## EPITECH PROJECT, 2022
## B-NWP-400-MPL-4-1-myftp-etienne.licheron
## File description:
## Makefile
##

SRC	= $(wildcard ./src/*.c)

OBJS = $(SRC:.c=.o)

EXE	= ./myftp

CFLAGS	= -I includes/ -g3

all:	$(EXE)

$(EXE): $(OBJS)
		$(CC) $(OBJS) -o $(EXE)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJSCLIENT)

fclean: clean
	$(RM) $(EXE)
	$(RM) $(OBJS)

re: fclean all