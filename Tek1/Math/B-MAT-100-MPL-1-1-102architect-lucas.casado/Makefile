##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## my make file
##

NAME	=	102architect

SRCS	= 	src/main.c \
			src/scaling.c \
			src/translation.c \
			src/rotation.c \

OBJS	=	$(SRCS:.c=.o)

NBR_OF_FILES := $(words $(SRCS))

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

RM	=	rm -f

CFLAGS += -I ./include/
CFLAGS += -g3 -lm -g -g3 -Wall -Wextra -I./lib/my

all: $(NAME)

$(NAME): $(OBJS)
		@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;34m$(NBR_OF_FILES)\033[0m"
		@ $(CC) -o $(NAME) $(OBJS) $(CFLAGS)
		@ echo "\033[1;34mBinary : \033[1;32m$(NAME)\033[1;34m created sucesfully.\033[0m"

clean:
		@ echo "\033[3;31mRemoving: \033[0m"
		@ echo "\033[3;31m$(OBJS)\033[0m" | tr ' ' '\n'
		@ $(RM) $(OBJS)
		@ $(RM) *~
		@ $(RM) *#
		@ $(RM) *.o

fclean:	clean
		@ echo "\033[3;31m./$(NAME)\033[0m"
		@ $(RM) $(NAME)
		@ $(RM) $(OBJS)
		@ $(RM) *~
		@ $(RM) *#
		@ $(RM) *.o

re: 	fclean all

%.o:	%.c
		@ echo "\033[1;34m[ OK ]\033[0m Compiling" $<
		@ $(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all clean fclean re