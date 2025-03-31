/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Misc.hpp
*/

#ifndef BOMBERMAN_MISC_HPP
#define BOMBERMAN_MISC_HPP

#include "raylib.h"

namespace Raylib {
    namespace Core {
        class Misc {
            public:
                Misc();
                ~Misc();

                int getRandomValue(int min, int max);
                void setRandomSeed(unsigned int seed);
                void takeScreenshot(const char *fileName);
                void setConfigFlags(unsigned int flags);
                void traceLog(int logLevel, const char *text, ...);
                void setTraceLogLevel(int logLevel);
                void *memAlloc(int size);
                void *memRealloc(void *ptr, int size);
                void memFree(void *ptr);
        };
    }
}

#endif
