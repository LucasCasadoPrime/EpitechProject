##
## EPITECH PROJECT, 2022
## B-PSU-400-MPL-4-1-nmobjdump-lucas.casado
## File description:
## Makefile
##

NMNAME	= my_nm

OBJNAME	= my_objdump

CC	= gcc

RM	= rm -f

NMSRCS	= nm/main.c \
	nm/engine.c \
	nm/find_type.c \

OBJSRCS	= objdump/main.c \
	objdump/engine.c \
	objdump/header.c \
	objdump/objdump.c

NMOBJS	= $(NMSRCS:.c=.o)

OBJOBJS	= $(OBJSRCS:.c=.o)

CFLAGS = -I ./nm/include -I ./objdump/include
CFLAGS += -W -Wall -Wextra

all: nm objdump

nm: $(NMOBJS)
	$(CC) $(NMOBJS) -o $(NMNAME) $(LDFLAGS)

objdump: $(OBJOBJS)
	$(CC) $(OBJOBJS) -o $(OBJNAME) $(LDFLAGS)

clean:
	$(RM) ./my_objdump
	$(RM) ./my_nm

fclean: clean
	make fclean -C objdump/
	make fclean -C nm/

re: fclean all