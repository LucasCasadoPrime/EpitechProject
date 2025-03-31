CC = gcc
SRC = string.c
TEST_SRC = $(wildcard tests/*.c)
CFLAGS = -W -Wall -Wextra -std=gnu17 -g3
TEST_FLAGS = $(CFLAGS) -lcriterion --coverage
OBJ = $(SRC:.c=.o)
TARGET = libstring.a
TEST_NAME = test

all: $(TARGET)

$(TARGET): $(OBJ)
	$(AR) rsc $(TARGET) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)
	$(RM) *.gcno
	$(RM) *.gncda
	$(RM) *.o
	$(RM) *.out
	$(RM) $(TEST_NAME)

re: fclean all

tests_run: fclean
	$(CC) $(TEST_SRC) $(SRC) $(TEST_FLAGS) -o $(TEST_NAME)
	./$(TEST_NAME)