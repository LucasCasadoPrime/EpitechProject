/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Speed
*/

#ifndef SPEED_HPP_
#define SPEED_HPP_

#include "Raylib.hpp"

namespace Bomberman {
    namespace PowerUp {
        class Speed {
        public:
            Speed(Vector3 position);
            ~Speed();
            Raylib::Models::ModelB* getModel();
            Vector3 getPosition();

        private:
            Raylib::Models::ModelB* _model;
            Vector3 _position;
        };
    }
}

#endif /* !SPEED_HPP_ */