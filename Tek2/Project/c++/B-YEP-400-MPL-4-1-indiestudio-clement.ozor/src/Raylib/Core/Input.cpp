/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Input.cpp
*/

#include "Input.hpp"

Raylib::Core::Input::Input() {}

Raylib::Core::Input::~Input() {}

bool Raylib::Core::Input::isKeyPressed(int key) {
    return IsKeyPressed(key);
}

bool Raylib::Core::Input::isKeyDown(int key) {
    return IsKeyDown(key);
}

bool Raylib::Core::Input::isKeyReleased(int key) {
    return IsKeyReleased(key);
}

bool Raylib::Core::Input::isKeyUp(int key) {
    return IsKeyUp(key);
}

void Raylib::Core::Input::setExitKey(int key) {
    SetExitKey(key);
}

int Raylib::Core::Input::getKeyPressed() {
    return GetKeyPressed();
}

int Raylib::Core::Input::getCharPressed() {
    return GetCharPressed();
}

bool Raylib::Core::Input::isMouseButtonPressed(int button) {
    return IsMouseButtonPressed(button);
}

bool Raylib::Core::Input::isMouseButtonDown(int button) {
    return IsMouseButtonDown(button);
}

bool Raylib::Core::Input::isMouseButtonReleased(int button) {
    return IsMouseButtonReleased(button);
}

bool Raylib::Core::Input::isMouseButtonUp(int button) {
    return IsMouseButtonUp(button);
}

int Raylib::Core::Input::getMouseX() {
    return GetMouseX();
}

int Raylib::Core::Input::getMouseY() {
    return GetMouseY();
}

Vector2 Raylib::Core::Input::getMousePosition() {
    return GetMousePosition();
}

Vector2 Raylib::Core::Input::getMouseDelta() {
    return GetMouseDelta();
}

void Raylib::Core::Input::setMousePosition(int x, int y) {
    SetMousePosition(x, y);
}

void Raylib::Core::Input::setMouseOffset(int offsetX, int offsetY) {
    SetMouseOffset(offsetX, offsetY);
}

void Raylib::Core::Input::setMouseScale(float scaleX, float scaleY) {
    SetMouseScale(scaleX, scaleY);
}

float Raylib::Core::Input::getMouseWheelMove() {
    return GetMouseWheelMove();
}

void Raylib::Core::Input::setMouseCursor(int cursor) {
    SetMouseCursor(cursor);
}
