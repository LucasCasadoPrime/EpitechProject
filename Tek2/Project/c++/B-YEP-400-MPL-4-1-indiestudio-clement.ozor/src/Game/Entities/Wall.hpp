/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Wall.hpp
*/

#ifndef BOMBERMAN_WALL_HPP
#define BOMBERMAN_WALL_HPP

#include "Raylib.hpp"

namespace Bomberman {
    namespace Entities {
        class Wall {
            public:
                Wall(Vector3 position);
                ~Wall();
                Raylib::Models::ModelB *getModel();
                Vector3 getPosition();

            private:
                Vector3 _position;
                Raylib::Models::ModelB *_model;
        };
    }
}

#endif
