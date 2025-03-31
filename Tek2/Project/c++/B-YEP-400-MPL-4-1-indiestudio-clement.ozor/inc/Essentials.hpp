/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Essentials.hpp
*/

#ifndef INDIESTUDIO_ESSENTIALS_HPP
#define INDIESTUDIO_ESSENTIALS_HPP

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 600

#define EMPTY_CHARACTER '0'
#define WALL_CHARACTER '1'
#define BOX_CHARACTER '7'

#define MAP_WIDTH 13
#define MAP_HEIGHT 15

#if _WIN32
    #include <string>
    #include <random>
    #include <iostream>
    #include <fstream>
    #include <vector>

#else
    #include <string>
    #include <ostream>
    #include <iostream>
    #include <vector>
    #include <unistd.h>
    #include <list>
    #include <fstream>
    #include <chrono>
    #include <random>
    #include <time.h>
#endif

namespace Bomberman {
    enum State {
        MENU_STATE,
        GAME_SOLO_STATE,
        GAME_MULT_STATE,
        PAUSE_STATE,
        END_WIN_STATE,
        END_LOOSE_STATE,
        MULT_END_WIN1_STATE,
        MULT_END_WIN2_STATE
    };
}

#endif