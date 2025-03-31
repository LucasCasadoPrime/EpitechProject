/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Misc.cpp
*/

#include "Misc.hpp"

Raylib::Core::Misc::Misc() {}

Raylib::Core::Misc::~Misc() {}

int Raylib::Core::Misc::getRandomValue(int min, int max) {
    return GetRandomValue(min, max);
}

void Raylib::Core::Misc::setRandomSeed(unsigned int seed) {
    SetRandomSeed(seed);
}

void Raylib::Core::Misc::takeScreenshot(const char *fileName) {
    TakeScreenshot(fileName);
}

void Raylib::Core::Misc::setConfigFlags(unsigned int flags) {
    SetConfigFlags(flags);
}

void Raylib::Core::Misc::traceLog(int logLevel, const char *text, ...) {
    va_list args;

    va_start(args, text);
    TraceLog(logLevel, text, args);
    va_end(args);
}

void Raylib::Core::Misc::setTraceLogLevel(int logLevel) {
    SetTraceLogLevel(logLevel);
}

void *Raylib::Core::Misc::memAlloc(int size) {
    return MemAlloc(size);
}

void *Raylib::Core::Misc::memRealloc(void *ptr, int size) {
    return MemRealloc(ptr, size);
}

void Raylib::Core::Misc::memFree(void *ptr) {
    MemFree(ptr);
}