##
## EPITECH PROJECT, 2021
## solver
## File description:
## Makefile
##

CC			=	gcc
CFLAGS		=	-I./includes -W -Wall -Wextra -g3

SRCS		=	$(wildcard main.c ./src/*.c)
SRC 		+= ./main.c
OBJS		=	$(SRCS:.c=.o)

TARGET		=	solver

all			:	$(TARGET)

$(TARGET)	:	$(OBJS)
			$(CC) -o $@ $^ $(LDFLAGS) -I./include
			@ echo "\033[1;34mBinary : \033[1;35m$(TARGET)\033[1;34m created sucesfully.\033[0m"

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(TARGET)

re			:	fclean all
