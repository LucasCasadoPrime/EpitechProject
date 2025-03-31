/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Sound.hpp
*/

#ifndef BOMBERMAN_SOUND_HPP
#define BOMBERMAN_SOUND_HPP

#include "raylib.h"
#include "Essentials.hpp"

namespace Raylib {
    namespace Audio {
        class SoundB {
            public:
                SoundB(const std::string &fileName);
                ~SoundB();
                void play();
                bool isPlaying();
                void stop();
                void pause();
                void resume();
                void setVolume(float volume);

            private:
                std::string _path;
                Sound _sound;
        };
    }
}

#endif
