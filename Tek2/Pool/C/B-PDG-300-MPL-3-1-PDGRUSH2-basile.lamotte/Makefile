##
## EPITECH PROJECT, 2022
## B-PDG-300-MPL-3-1-PDGD04am-basile.lamotte
## File description:
## Makefile
##

.PHONY: all clean fclean re

SRC := $(wildcard *.c)

OBJ = $(SRC:.c=.o)

CFLAGS += -std=gnu17 -g

NAME = rush

$(NAME): $(OBJ)
		@echo building $@
		gcc -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:	fclean all