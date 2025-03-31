/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Monitor.cpp
*/

#include "Monitor.hpp"

Raylib::Core::Monitor::Monitor() {
    _monitor = GetCurrentMonitor();
}

Raylib::Core::Monitor::Monitor(int monitor): _monitor(monitor) {}

Raylib::Core::Monitor::~Monitor() = default;

int Raylib::Core::Monitor::getCurrent() {
    return (GetCurrentMonitor());
}

int Raylib::Core::Monitor::getHeight() const {
    return (GetMonitorHeight(_monitor));
}

int Raylib::Core::Monitor::getWidth() const {
    return (GetMonitorWidth(_monitor));
}