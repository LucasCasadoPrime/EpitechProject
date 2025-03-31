CC = ghc

SRC = Main.hs 

NAME = pushswap_checker

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC)

clean:
	$(RM) $(SRC:.hs=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all
