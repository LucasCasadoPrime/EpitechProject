/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Timing.hpp
*/

#ifndef BOMBERMAN_TIMING_HPP
#define BOMBERMAN_TIMING_HPP

#include "raylib.h"

namespace Raylib {
    namespace Core {
        class Timing {
            public:
                Timing();
                ~Timing();

                void setTargetFPS(int fps);
                int getFPS(void);
                float getFrameTime(void);
                double getTime(void);
        };
    }
}

#endif
