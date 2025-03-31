/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "iGame.hpp"

namespace arcade
{
    class menu : public iGame {
        public:
            menu();
            ~menu();
            void init();
            std::string getName();
            std::vector<std::pair<entitiesType, entities *>> runtime(int key, int &_game, bool &_running);;
    };
}

#endif /* !MENU_HPP_ */