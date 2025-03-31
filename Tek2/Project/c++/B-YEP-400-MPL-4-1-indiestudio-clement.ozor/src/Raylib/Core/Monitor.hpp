/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Monitor.hpp
*/

#ifndef BOMBERMAN_MONITOR_HPP
#define BOMBERMAN_MONITOR_HPP

#include "Raylib.hpp"

namespace Raylib {
    namespace Core {
        class Monitor {
            public:
                Monitor();
                Monitor(int monitor);
                ~Monitor();

                int getCurrent();
                int getWidth() const;
                int getHeight() const;

            private:
                int _monitor;
        };
    }
}

#endif
