/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Core.hpp
*/

#ifndef INDIESTUDIO_CURSOR_HPP
#define INDIESTUDIO_CURSOR_HPP

#include "raylib.h"

namespace Raylib {
    namespace Core {
        class Cursor {
            public:
                Cursor();
                ~Cursor();

                void ShowCursor();
                void HideCursor();
                bool IsCursorHidden();
                void EnableCursor();
                void DisableCursor();
                bool IsCursorOnScreen();
        };
    }
}

#endif
