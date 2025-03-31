##
## EPITECH PROJECT, 2021
## B-AIA-200-MPL-2-1-n4s-lucas.casado
## File description:
## Makefile
##

SRC	=	main.c \
	src/executable.c \
	src/drive.c \
	src/speed.c \
	src/stwa.c \
	src/direction.c \
	src/utils.c \
	src/basic.c \
	src/read.c

OBJ	= $(SRC:.c=.o)

CFLAGS	+=	-Wall -Werror -Wextra \
		-I include

NAME	= ai

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all