##
## EPITECH PROJECT, 2021
##
##

CC	= gcc

SRC	= src/main.c \
	src/utils.c \
	src/gameplay.c \
	src/verifmap.c \
	src/stwa.c \
	src/event.c \
	src/checker.c \
	src/movecrates.c \
	src/win.c \
	src/print.c \
	src/checker2.c

NAME	= my_sokoban

OBJ	=  $(SRC:.c=.o)

FLAGS	= -I./include -lncurses -g3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all