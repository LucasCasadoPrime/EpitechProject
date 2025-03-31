/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** sdl2
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_

#include "iGraphical.hpp"
#include "Keys.hpp"
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

namespace arcade {
    class sdl2 : public iGraphical{
        private:
            SDL_Window* _window;
            SDL_Renderer* _renderer;
            SDL_Event _event;
            TTF_Font* _font;
        public:
            sdl2();
            ~sdl2();
            void close();
            void display(std::vector<std::pair<entitiesType, entities *>> ent);
            void displaySprite(sprite *sprite);
            void erase();
            int handleKeys();
            void displayText(text_s *text);
            void displayBox();

            void init();
            std::string getName();
    };
}

#endif /* !SDL2_HPP_ */
