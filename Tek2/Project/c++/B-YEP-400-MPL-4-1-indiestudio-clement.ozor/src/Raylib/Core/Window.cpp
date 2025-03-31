/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Window.cpp
*/

#include "Window.hpp"

#include <utility>

Raylib::Core::Window::Window(int width, int height, std::string title):
_width(width), _height(height), _title(std::move(title)) {
    InitWindow(_width, _height, _title.c_str());
}

Raylib::Core::Window::~Window() {
    CloseWindow();
}

bool Raylib::Core::Window::shouldClose() {
    return WindowShouldClose();
}

bool Raylib::Core::Window::isReady() {
    return IsWindowReady();
}

void Raylib::Core::Window::setIcon(Image icon) {
    _icon = icon;
    SetWindowIcon(icon);
}

void Raylib::Core::Window::setTitle(std::string title) {
    _title = title;
    SetWindowTitle(title.c_str());
}

void Raylib::Core::Window::setPosition(int x, int y) {
    _x = x;
    _y = y;
    SetWindowPosition(x, y);
}

void Raylib::Core::Window::setSize(int width, int height) {
    _width = width;
    _height = height;
    SetWindowSize(width, height);
}

int Raylib::Core::Window::getWidth() {
    return GetScreenWidth();
}

int Raylib::Core::Window::getHeight() {
    return GetScreenHeight();
}

Vector2 Raylib::Core::Window::getPosition() {
    return GetWindowPosition();
}

void Raylib::Core::Window::toggleFullscreen() {
    ToggleFullscreen();
}