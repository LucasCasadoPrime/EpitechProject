CC	= g++

SRC	= unit.cpp

NAME = my_convert_temp

OBJ	=  $(SRC:.cpp=.o)

FLAGS	=  -std=c++20 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all