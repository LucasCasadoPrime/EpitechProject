/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** WallPass
*/

#ifndef WALLPASS_HPP_
#define WALLPASS_HPP_

#include "Raylib.hpp"

namespace Bomberman {
    namespace PowerUp {
        class WallPass {
        public:
            WallPass(Vector3 position);
            ~WallPass();
            Raylib::Models::ModelB* getModel();
            Vector3 getPosition();

        private:
            Raylib::Models::ModelB* _model;
            Vector3 _position;
        };
    }
}

#endif /* !WALLPASS_HPP_ */