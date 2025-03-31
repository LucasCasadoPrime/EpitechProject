##
## EPITECH PROJECT, 2022
## B-CCP-400-MPL-4-1-panoramix-lucas.casado
## File description:
## Makefile
##


########## COLORS ##########
RESET            =    \033[0m
BOLD            =    \033[1m
GREY            =    \033[30m
RED                =    \033[31m
GREEN            =    \033[32m
YELLOW            =    \033[33m
BLUE            =    \033[34m
PURPLE            =    \033[35m
CYAN            =    \033[36m
WHITE            =    \033[37m
############################

CC    = g++

SRC		= $(wildcard ./src/*.cpp)

NAME    = plazza

OBJ    =  $(SRC:.cpp=.o)

FLAGS    = -Iinclude -lpthread



all:
	$(MAKE) -j8 compile

compile: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BOLD)$(GREEN)Binary Compilation...$(RESET)"
	$(CC) $(OBJ) -o $(NAME) $(FLAGS)
	@echo "$(BOLD)$(RED)[OK] $(YELLOW)Compilated binary$(PURPLE) [$(NAME)]$(RESET)"

clean:
	@echo "$(BOLD)$(RED)Removing files...$(RESET)"
	@$(RM) $(OBJ)
	@$(RM) commande.tmp

fclean: clean
	@$(RM) $(NAME)

re: fclean all