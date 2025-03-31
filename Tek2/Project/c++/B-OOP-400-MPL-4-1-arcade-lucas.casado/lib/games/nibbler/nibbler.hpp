/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "iGame.hpp"
#include <iostream>
#include <fstream>
#include <string>

namespace arcade
{
    class nibbler : public iGame {
        public:
            nibbler();
            ~nibbler();
            void init();
            std::string getName();
            std::vector<std::pair<entitiesType, entities *>> runtime(int key, int &_game, bool &_running);;
    };
}


#endif /* !NIBBLER_HPP_ */
