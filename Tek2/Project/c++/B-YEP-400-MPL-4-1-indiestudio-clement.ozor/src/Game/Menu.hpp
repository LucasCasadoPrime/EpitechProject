/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-clement.ozor
** File description:
** Menu.hpp
*/

#ifndef BOMBERMAN_MENU_HPP
#define BOMBERMAN_MENU_HPP

#include "Essentials.hpp"
#include "Raylib.hpp"
#include "raylib.h"

namespace Bomberman {
    class Menu {
    public:
        void draw(Raylib::Core::Window* window, Bomberman::State* state);
        void handleInput(void);
        void handle_solo_input(Vector2 mouse_position);
        void handle_multi_input(Vector2 mouse_position);
        void handle_quit_input(Vector2 mouse_position);
        Menu(Raylib::Core::Window* window, Bomberman::State* state, Bomberman::State* currState);
        ~Menu(void) {};
        bool getHasMusicChange();
        void setHasMusicChange(bool hasMusicChange);
    private:
        Raylib::Core::Window* _window = nullptr;
        Bomberman::State* _state = nullptr;
        Bomberman::State* _currGameState = nullptr;
        Raylib::Texture::Tex* _fond_tex = nullptr;
        Raylib::Texture::Tex* _title_tex = nullptr;
        Raylib::Texture::Tex* _solo_tex = nullptr;
        Raylib::Texture::Tex* _multi_tex = nullptr;
        Raylib::Texture::Tex* _quit_tex = nullptr;
        Raylib::Texture::Tex* _solo_tex_idle = nullptr;
        Raylib::Texture::Tex* _solo_tex_hover = nullptr;
        Raylib::Texture::Tex* _multi_tex_idle = nullptr;
        Raylib::Texture::Tex* _multi_tex_hover = nullptr;
        Raylib::Texture::Tex* _quit_tex_idle = nullptr;
        Raylib::Texture::Tex* _quit_tex_hover = nullptr;
        bool _hasMusicChange;
    };
}

#endif