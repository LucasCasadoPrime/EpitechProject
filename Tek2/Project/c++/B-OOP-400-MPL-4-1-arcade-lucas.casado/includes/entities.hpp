/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** entities
*/

#ifndef ENTITIES_HPP_
#define ENTITIES_HPP_

#include <string>

namespace arcade
{
    enum entitiesType {
        text_t,
        sprite_t,
    };

    typedef struct RGB_s {
        float r;
        float g;
        float b;
    }RGB;

    typedef struct pos {
        float x;
        float y;
    }pos_s;
    typedef struct entities_s {
        pos_s pos;
        float scale;
    }entities;

    typedef struct sprite : entities {
        char symbol; // for ncurses
        std::string texturePath;
    }sprite_s;

    typedef struct text : entities {
        std::string text;
        std::string font;
        RGB color;
    }text_s;
} // namespace arcade



#endif /* !ENTITIES_HPP_ */
