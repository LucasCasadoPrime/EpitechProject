/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "iGame.hpp"

namespace arcade
{
    class pacman : public iGame {
        public:
            pacman();
            ~pacman();
            void init();
            std::string getName();
            std::vector<std::pair<entitiesType, entities *>> runtime(int key, int &_game, bool &_running);;
    };
} // namespace arcade

#endif /* !PACMAN_HPP_ */
