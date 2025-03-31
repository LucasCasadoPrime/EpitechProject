##
## EPITECH PROJECT, 2022
## B-PSU-400-MPL-4-1-malloc-lucas.casado
## File description:
## Makefile
##

SRC	= src/malloc_function.c \
	src/block_management.c \
	src/create_page.c


CFLAGS = -Wall -Wextra -Wno-deprecated -fPIC -I include/

OBJS = $(SRC:.c=.o)

NAME = libmy_malloc.so

all: $(NAME)

$(NAME): $(OBJS)
	gcc -fPIC -shared -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all