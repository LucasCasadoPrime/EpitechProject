/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** ScreenSpace.hpp
*/

#ifndef BOMBERMAN_SCREENSPACE_HPP
#define BOMBERMAN_SCREENSPACE_HPP

#include "raylib.h"

namespace Raylib {
    namespace Core {
        class ScreenSpace {
            public:
                ScreenSpace();
                ~ScreenSpace();

                Ray getMouseRay(Vector2 mousePosition, Camera camera);
                Matrix getCameraMatrix(Camera camera);
                Matrix getCameraMatrix2D(Camera2D camera);
                Vector2 getWorldToScreen(Vector3 position, Camera camera);
                Vector2 getWorldToScreenEx(Vector3 position, Camera camera, int width, int height);
                Vector2 getWorldToScreen2D(Vector2 position, Camera2D camera);
        };
    }
}

#endif
