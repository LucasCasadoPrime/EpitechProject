/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Entity.hpp
*/

#ifndef BOMBERMAN_ENTITY_HPP
#define BOMBERMAN_ENTITY_HPP

#include "Raylib.hpp"
#include "Player.hpp"
#include "Bomb.hpp"
#include "Wall.hpp"
#include "Box.hpp"

namespace Bomberman {
    namespace Entities {
        class Entities {
            public:
                Entities();
                ~Entities();
                void addPlayer(Player *player);
                void addWall(Wall *wall);
                void addBox(Box *box);
                void removePlayer(int position);
                void removeWall(int position);
                void removeBox(int position);
                void destroy(void);
                std::vector<Player *> getPlayers();
                std::vector<Wall *> getWalls();
                std::vector<Box *> getBoxes();

            private:
                std::vector<Player *> _players;
                std::vector<Wall *> _walls;
                std::vector<Box *> _boxes;
        };
    }
}
#endif
