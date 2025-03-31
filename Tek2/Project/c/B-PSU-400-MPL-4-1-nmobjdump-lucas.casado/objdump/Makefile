##
## EPITECH PROJECT, 2022
## B-PSU-400-MPL-4-1-nmobjdump-lucas.casado
## File description:
## Makefile
##

NAME = my_objdump

CC = gcc

RM = rm -f

SRCS = ./main.c \
	./engine.c \
	./header.c \
	./objdump.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include
CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all