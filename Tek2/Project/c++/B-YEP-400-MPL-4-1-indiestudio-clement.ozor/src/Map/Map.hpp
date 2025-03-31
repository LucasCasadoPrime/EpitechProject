/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-clement.ozor
** File description:
** map.hpp
*/

#ifndef BOMBERMAN_MAP_HPP
#define BOMBERMAN_MAP_HPP

#include "Essentials.hpp"

namespace Bomberman {
    class Map {
        public:
            void generateMap(void);
            void eraseMap(void);
            bool isGenerated(void);
            void setGenerated(bool);
            std::vector<std::string> getMap(void);
            Map(void) {};
            ~Map(void) {};
        private:
            bool generated = false;
            std::vector<std::string> _map;
    };
}

#endif