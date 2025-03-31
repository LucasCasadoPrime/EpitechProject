/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Input.hpp
*/

#ifndef BOMBERMAN_INPUT_HPP
#define BOMBERMAN_INPUT_HPP

#include "raylib.h"

namespace Raylib {
    namespace Core {
        class Input {
            public:
                Input();
                ~Input();

                // Keyboard
                bool isKeyPressed(int key);
                bool isKeyDown(int key);
                bool isKeyReleased(int key);
                bool isKeyUp(int key);
                void setExitKey(int key);
                int getKeyPressed(void);
                int getCharPressed(void);

                // Mouse
                bool isMouseButtonPressed(int button);
                bool isMouseButtonDown(int button);
                bool isMouseButtonReleased(int button);
                bool isMouseButtonUp(int button);
                int getMouseX(void);
                int getMouseY(void);
                Vector2 getMousePosition(void);
                Vector2 getMouseDelta(void);
                void setMousePosition(int x, int y);
                void setMouseOffset(int offsetX, int offsetY);
                void setMouseScale(float scaleX, float scaleY);
                float getMouseWheelMove(void);
                void setMouseCursor(int cursor);
        };
    }
}

#endif
