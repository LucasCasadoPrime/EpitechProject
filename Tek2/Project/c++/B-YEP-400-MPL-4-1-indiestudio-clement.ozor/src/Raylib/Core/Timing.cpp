/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Timing.cpp
*/

#include "Timing.hpp"

Raylib::Core::Timing::Timing() {}

Raylib::Core::Timing::~Timing() {}

void Raylib::Core::Timing::setTargetFPS(int fps) {
    SetTargetFPS(fps);
}

int Raylib::Core::Timing::getFPS() {
    return GetFPS();
}

float Raylib::Core::Timing::getFrameTime() {
    return GetFrameTime();
}

double Raylib::Core::Timing::getTime() {
    return GetTime();
}