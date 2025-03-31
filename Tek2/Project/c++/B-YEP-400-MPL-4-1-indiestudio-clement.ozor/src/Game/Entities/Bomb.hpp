/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Bomb.hpp
*/

#ifndef BOMBERMAN_BOMB_HPP
#define BOMBERMAN_BOMB_HPP

#include "Essentials.hpp"
#include "Raylib.hpp"
#if _WIN32
    #include "..\Timer.hpp"
#else
    #include "../Timer.hpp"
#endif

namespace Bomberman {
    namespace Entities {
        class Bomb {
            public:
                Bomb(Vector3 position);
                ~Bomb();
                void explode();
                void scaleUp(void);
                int getId(void);
                int getBombIndex(int id);
                void setExplode(bool value);
                bool isExplosing(void);
                Vector3 getPosition(void);
                Raylib::Models::ModelB *getModel();
                Bomberman::Timer *getTimer(void);

            private:
                int _power = 1;
                bool explosing = false;
                Bomberman::Timer *_timer;
                Vector3 _position;
                Raylib::Models::ModelB *_model;
        };
    }
}

#endif
