/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Sound.cpp
*/

#include "Sound.hpp"

Raylib::Audio::SoundB::SoundB(const std::string &fileName) {
    _path = fileName;
    _sound = LoadSound(_path.c_str());
}

Raylib::Audio::SoundB::~SoundB() {
    UnloadSound(_sound);
}

void Raylib::Audio::SoundB::play() {
    PlaySoundMulti(_sound);
}

void Raylib::Audio::SoundB::pause() {
    PauseSound(_sound);
}

void Raylib::Audio::SoundB::resume() {
    ResumeSound(_sound);
}

void Raylib::Audio::SoundB::stop() {
    StopSound(_sound);
}

void Raylib::Audio::SoundB::setVolume(float volume) {
    SetSoundVolume(_sound, volume);
}

bool Raylib::Audio::SoundB::isPlaying() {
    return IsSoundPlaying(_sound);
}