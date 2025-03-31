##
## EPITECH PROJECT, 2022
## B-OOP-400-MPL-4-1-arcade-lucas.casado
## File description:
## Makefile
##

CC 		= 	g++
RM 		= 	rm -f
TARGET_LIB 	= 	../lib/arcade_ncurses.so

SRCS		= 	./ncurses.cpp

OBJS 		= 	$(SRCS:.cpp=.o)

CXXFLAGS 	= 	-I ../../../includes
CXXFLAGS 	+= 	-W -Wall -Wextra -fPIC
LDFLAGS      	=	-shared -lncurses -rdynamic

all: $(TARGET_LIB)

$(TARGET_LIB): $(OBJS)
	 $(CXX) $(OBJS) -o ../../$(TARGET_LIB) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../../$(TARGET_LIB)

re: fclean all

.PHONY: all clean fclean re