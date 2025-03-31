/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Range
*/

#ifndef RANGE_HPP_
#define RANGE_HPP_

#include "Raylib.hpp"

namespace Bomberman {
    namespace PowerUp {
        class Range {
        public:
            Range(Vector3 position);
            ~Range();
            Raylib::Models::ModelB* getModel();
            Vector3 getPosition();

        private:
            Raylib::Models::ModelB* _model;
            Vector3 _position;
        };
    }
}

#endif /* !RANGE_HPP_ */
