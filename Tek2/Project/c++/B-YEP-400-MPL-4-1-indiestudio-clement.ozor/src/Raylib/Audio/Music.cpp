/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-clement.ozor
** File description:
** Audio.cpp
*/

#include "Music.hpp"

Raylib::Audio::MusicB::MusicB(const std::string &fileName) {
    _path = fileName;
    _music = LoadMusicStream(_path.c_str());
}

Raylib::Audio::MusicB::~MusicB() {
    UnloadMusicStream(_music);
}

void Raylib::Audio::MusicB::play() {
    PlayMusicStream(_music);
}

void Raylib::Audio::MusicB::stop() {
    StopMusicStream(_music);
}

void Raylib::Audio::MusicB::pause() {
    PauseMusicStream(_music);
}

void Raylib::Audio::MusicB::resume() {
    ResumeMusicStream(_music);
}

void Raylib::Audio::MusicB::setVolume(float volume) {
    SetMusicVolume(_music, volume);
}

bool Raylib::Audio::MusicB::isPlaying() {
    return IsMusicStreamPlaying(_music);
}

void Raylib::Audio::MusicB::update() {
    UpdateMusicStream(_music);
}