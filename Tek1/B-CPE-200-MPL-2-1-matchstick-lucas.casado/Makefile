##
## EPITECH PROJECT, 2021
##
##

CC	= gcc

SRC	= src/main.c \
	src/stwa.c \
	src/get_nbr.c \
	src/map.c \
	src/utils.c \
	src/utils_map.c \
	src/my_atoi.c \
	src/ai.c

NAME	= matchstick

OBJ	=  $(SRC:.c=.o)

FLAGS	= -I./include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all