/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** ScreenSpace.cpp
*/

#include "ScreenSpace.hpp"

Raylib::Core::ScreenSpace::ScreenSpace() {}

Raylib::Core::ScreenSpace::~ScreenSpace() {}

Ray Raylib::Core::ScreenSpace::getMouseRay(Vector2 mousePosition, Camera camera) {
    return GetMouseRay(mousePosition, camera);
}

Matrix Raylib::Core::ScreenSpace::getCameraMatrix(Camera camera) {
    return GetCameraMatrix(camera);
}

Matrix Raylib::Core::ScreenSpace::getCameraMatrix2D(Camera2D camera) {
    return GetCameraMatrix2D(camera);
}

Vector2 Raylib::Core::ScreenSpace::getWorldToScreen(Vector3 position, Camera camera) {
    return GetWorldToScreen(position, camera);
}

Vector2 Raylib::Core::ScreenSpace::getWorldToScreenEx(Vector3 position, Camera camera, int width, int height) {
    return GetWorldToScreenEx(position, camera, width, height);
}

Vector2 Raylib::Core::ScreenSpace::getWorldToScreen2D(Vector2 position, Camera2D camera) {
    return GetWorldToScreen2D(position, camera);
}