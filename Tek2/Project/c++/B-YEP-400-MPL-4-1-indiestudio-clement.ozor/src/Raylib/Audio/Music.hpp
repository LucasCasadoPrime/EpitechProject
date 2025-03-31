/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-clement.ozor
** File description:
** Audio.hpp
*/

#ifndef INDIESTUDIO_AUDIO_MUSIC_HPP
#define INDIESTUDIO_AUDIO_MUSIC_HPP

#include "raylib.h"
#include "Essentials.hpp"

namespace Raylib {
    namespace Audio {
        class MusicB {
            public:
                MusicB(const std::string &fileName);
                ~MusicB();
                void play();
                bool isPlaying();
                void stop();
                void pause();
                void resume();
                void setVolume(float volume);
                void update();

            private:
                std::string _path;
                Music _music;
        };
    }
}

#endif