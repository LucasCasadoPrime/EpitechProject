/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** main
*/

#include "arcade.hpp"
#include "Core.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include <cstddef>  

void display_help(void)
{
    std::cout << "                                               \033[1;35m __" << std::endl;
    std::cout << "                                              \033[1;35m (  )" << std::endl;
    std::cout << "\033[1;31m    ___ \033[1;32m   ____ \033[1;33m ______\033[1;34m___ \033[1;36m   ____ \033[1;35m ______      ||" << std::endl;
    std::cout << "\033[1;31m   /   | \033[1;32m / __ \\\033[1;33m/ ____/ \033[1;34m  | \033[1;36m / __ \\\033[1;35m/ ____/      ||" << std::endl;
    std::cout << "\033[1;31m  / /| | \033[1;32m/ /_/ \033[1;33m/ /   \033[1;34m/ /| |\033[1;36m / / /\033[1;35m / __/      ___|""|__.._" << std::endl;
    std::cout << "\033[1;31m / ___ |\033[1;32m/ _, _\033[1;33m/ /___\033[1;34m/ ___ |\033[1;36m/ /_/ \033[1;35m/ /___     /____________\\" << std::endl;
    std::cout << "\033[1;31m/_/  |_\033[1;32m/_/ |_|\033[1;33m\\____/\033[1;34m_/  |_\033[1;36m/_____\033[1;35m/_____/     \\____________/~~~.\033[1;30m" << std::endl << std::endl;

    std::cout << "Usage: arcade [library.so]" << std::endl;
    std::cout << " Run graphic library passed as argument." << std::endl << std::endl;
    std::cout << "Avaible libraries:" << std::endl;
    std::cout << "   ➤ Ncurses: findable as ./lib/arcade_ncurses.so" << std::endl;
    std::cout << "   ➤ SDL2: findable as ./lib/arcade_sdl2.so" << std::endl;
    std::cout << "   ➤ SFML: findable as ./lib/arcade_sfml.so" << std::endl;
    std::cout << "Avaible games:" << std::endl;
    std::cout << "   ➤ Pacman: findable as ./lib/arcade_pacman.so" << std::endl;
    std::cout << "   ➤ Nibbler: findable as ./lib/arcade_nibbler.so" << std::endl;
}

void check_errors(int ac, char **av)
{
    std::string file;

    if (ac > 2) {
        std::cout << "\033[1;31mArcade: Only one argument is required. Use './arcade -h' for more informations" << std::endl;
        exit (84);
    }
    if (ac < 2) {
        std::cout << "\033[1;31mArcade: Need at least one argument. Use './arcade -h' for more informations" << std::endl;
        exit (84);
    }
    file = av[1];
    if (!file.compare("-h")) {
        display_help();
        exit (0);
    }
}

int main(int ac, char **av)
{
    check_errors(ac, av);
    arcade::Core core(av[1]);
    core.loadLibraries();
    core.runtime();
    return (0);
}