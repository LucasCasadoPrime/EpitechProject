/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Audio.cpp
*/

#include "Audio.hpp"

Raylib::Audio::Audio::Audio() {
    InitAudioDevice();
}

Raylib::Audio::Audio::~Audio() {
    CloseAudioDevice();
}

bool Raylib::Audio::Audio::isReady() {
    return (IsAudioDeviceReady());
}

void Raylib::Audio::Audio::setVolume(float volume) {
    SetMasterVolume(volume);
}