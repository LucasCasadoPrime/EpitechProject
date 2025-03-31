/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Animation.hpp
*/

#ifndef BOMBERMAN_ANIMATION_HPP
#define BOMBERMAN_ANIMATION_HPP

#include "Essentials.hpp"
#include "raylib.h"

namespace Raylib {
    namespace Models {
        class Animation {
            public:
                Animation(const std::string &fileName, unsigned int *animCount);
                ~Animation();

                void updateModelAnimation(Model model, ModelAnimation anim, int frame);
                bool isModelAnimationValid(Model model, ModelAnimation anim);

            private:
                ModelAnimation *_animations;
                int _animCount;
        };
    }
}

#endif