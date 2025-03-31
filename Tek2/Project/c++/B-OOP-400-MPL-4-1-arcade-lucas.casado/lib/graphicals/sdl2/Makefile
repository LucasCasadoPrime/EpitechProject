##
## EPITECH PROJECT, 2022
## B-OOP-400-MPL-4-1-arcade-lucas.casado
## File description:
## Makefile
##

CC 		= 	g++
RM 		= 	rm -f
TARGET_LIB 	= 	../lib/arcade_sdl2.so

SRCS		= 	./sdl2.cpp

OBJS 		= 	$(SRCS:.cpp=.o)

CXXFLAGS 	= 	-I ../../../includes
CXXFLAGS 	+= 	-W -Wall -Wextra -fPIC
LDFLAGS		=	-shared -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -rdynamic

all: $(TARGET_LIB)

$(TARGET_LIB): $(OBJS)
	 $(CXX) $(OBJS) -o ../../$(TARGET_LIB) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../../$(TARGET_LIB)

re: fclean all

.PHONY: all clean fclean re