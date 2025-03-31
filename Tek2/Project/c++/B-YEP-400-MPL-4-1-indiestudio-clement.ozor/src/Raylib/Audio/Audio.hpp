/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Audio.hpp
*/

#ifndef BOMBERMAN_AUDIO_HPP
#define BOMBERMAN_AUDIO_HPP

#include "raylib.h"

namespace Raylib {
    namespace Audio {
        class Audio {
            public:
                Audio();
                ~Audio();

                bool isReady(void);
                void setVolume(float volume);
        };
    }
}

#endif
