/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "Raylib.hpp"

#if _WIN32
    namespace Bomberman {
        namespace PowerUp {
            class Bomb {
            public:
                Bomb(Vector3 position);
                ~Bomb();
                Raylib::Models::ModelB* getModel();
                Vector3 getPosition();

            private:
                Raylib::Models::ModelB* _model;
                Vector3 _position;
            };
        }
    }
#else
    namespace Bomberman::PowerUp {
        class Bomb {
        public:
            Bomb(Vector3 position);
            ~Bomb();
            Raylib::Models::ModelB* getModel();
            Vector3 getPosition();

        private:
            Raylib::Models::ModelB* _model;
            Vector3 _position;
        };
    }
#endif

#endif /* !BOMB_HPP_ */
