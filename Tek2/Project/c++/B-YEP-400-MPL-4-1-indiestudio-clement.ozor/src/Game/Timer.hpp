/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-clement.ozor
** File description:
** Timer.hpp
*/

#ifndef BOMBERMAN_TIMER_HPP
#define BOMBERMAN_TIMER_HPP

#include "Raylib.hpp"

namespace Bomberman {
    class Timer {
        public:
            Timer(float time);
            ~Timer(void) {};
            void updateTimer(void);
            bool timerDone(void);
            void setTimer(float value);
        private:
            float _timer;
    };
}

#endif