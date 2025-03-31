/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** iGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include "iLibrary.hpp"
#include "Keys.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <utility>
namespace arcade
{
    typedef std::vector<std::pair<arcade::entitiesType, entities *>> allEntities;
    class iGame : public iLibrary {
        private:
        public:
            virtual ~iGame() = default;
            virtual std::vector<std::pair<entitiesType, entities *>> runtime(int key, int &_game, bool &_running) = 0;
    };    
} // namespace arcade


#endif /* !IGAME_HPP_ */
