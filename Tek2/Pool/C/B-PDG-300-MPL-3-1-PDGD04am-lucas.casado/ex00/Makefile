##
## EPITECH PROJECT, 2022
##
##

CC	= gcc

SRC	= z.c

NAME = z

OBJ	=  $(SRC:.c=.o)

FLAGS	= -std=gnu17 -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all