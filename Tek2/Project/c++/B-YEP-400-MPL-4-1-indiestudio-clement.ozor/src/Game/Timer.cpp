/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-clement.ozor
** File description:
** Timer.cpp
*/

#include "Timer.hpp"


Bomberman::Timer::Timer(float time)
{
    this->_timer = time;
}

void Bomberman::Timer::updateTimer(void)
{
    this->_timer -= GetFrameTime();
}

bool Bomberman::Timer::timerDone(void)
{
    return (this->_timer <= 0.0f);
}

void Bomberman::Timer::setTimer(float value)
{
    this->_timer = value;
}