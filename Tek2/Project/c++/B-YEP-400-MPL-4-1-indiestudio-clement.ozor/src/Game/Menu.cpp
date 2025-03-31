/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-clement.ozor
** File description:
** Menu.cpp
*/

#include "Menu.hpp"
#include "Game.hpp"

Bomberman::Menu::Menu(Raylib::Core::Window* window, Bomberman::State* state, Bomberman::State* currState)
{
#if _WIN32
    Raylib::Texture::Img fond("..\\assets\\images\\menu\\Background.png");
    Raylib::Texture::Img title("..\\assets\\images\\menu\\Title.png");
    Raylib::Texture::Img solo_idle("..\\assets\\images\\menu\\Solo_idle.png");
    Raylib::Texture::Img solo_hover("..\\assets\\images\\menu\\Solo_selected.png");
    Raylib::Texture::Img multi_idle("..\\assets\\images\\menu\\Multi_idle.png");
    Raylib::Texture::Img multi_hover("..\\assets\\images\\menu\\Multi_selected.png");
    Raylib::Texture::Img quitter_idle("..\\assets\\images\\menu\\Quit_idle.png");
    Raylib::Texture::Img quitter_hover("..\\assets\\images\\menu\\Quit_selected.png");
#else
    Raylib::Texture::Img fond("assets/images/menu/Background.png");
    Raylib::Texture::Img title("assets/images/menu/Title.png");
    Raylib::Texture::Img solo_idle("assets/images/menu/Solo_idle.png");
    Raylib::Texture::Img solo_hover("assets/images/menu/Solo_selected.png");
    Raylib::Texture::Img multi_idle("assets/images/menu/Multi_idle.png");
    Raylib::Texture::Img multi_hover("assets/images/menu/Multi_selected.png");
    Raylib::Texture::Img quitter_idle("assets/images/menu/Quit_idle.png");
    Raylib::Texture::Img quitter_hover("assets/images/menu/Quit_selected.png");
#endif

    this->_fond_tex = new Raylib::Texture::Tex(fond.getImage());
    this->_title_tex = new Raylib::Texture::Tex(title.getImage());
    this->_solo_tex_idle = new Raylib::Texture::Tex(solo_idle.getImage());
    this->_solo_tex_hover = new Raylib::Texture::Tex(solo_hover.getImage());
    this->_multi_tex_idle = new Raylib::Texture::Tex(multi_idle.getImage());
    this->_multi_tex_hover = new Raylib::Texture::Tex(multi_hover.getImage());
    this->_quit_tex_idle = new Raylib::Texture::Tex(quitter_idle.getImage());
    this->_quit_tex_hover = new Raylib::Texture::Tex(quitter_hover.getImage());

    this->_solo_tex = this->_solo_tex_idle;
    this->_multi_tex = this->_multi_tex_idle;
    this->_quit_tex = this->_quit_tex_idle;

    this->_window = window;
    this->_state = state;
    this->_currGameState = currState;
}

void Bomberman::Menu::handle_solo_input(Vector2 mouse_position)
{
    float XPos = this->_window->getWidth() - 575;
    Rectangle btnBounds = { XPos, 200, 575, 80 };
    if (CheckCollisionPointRec(mouse_position, btnBounds)) {
        this->_solo_tex = this->_solo_tex_hover;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            (*this->_state) = Bomberman::GAME_SOLO_STATE;
            _hasMusicChange = false;
            (*this->_currGameState) = GAME_SOLO_STATE;
        }
    }
    else
        this->_solo_tex = this->_solo_tex_idle;
}

void Bomberman::Menu::handle_multi_input(Vector2 mouse_position)
{
    float XPos = this->_window->getWidth() - 575;
    Rectangle btnBounds = { XPos, 350, 575, 80 };
    if (CheckCollisionPointRec(mouse_position, btnBounds)) {
        this->_multi_tex = this->_multi_tex_hover;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            (*this->_state) = Bomberman::GAME_MULT_STATE;
            _hasMusicChange = false;
            (*this->_currGameState) = GAME_MULT_STATE;
        }
    }
    else
        this->_multi_tex = this->_multi_tex_idle;
}

void Bomberman::Menu::handle_quit_input(Vector2 mouse_position)
{
    float XPos = this->_window->getWidth() - 575;
    Rectangle btnBounds = { XPos, 800, 575, 80 };
    if (CheckCollisionPointRec(mouse_position, btnBounds)) {
        this->_quit_tex = this->_quit_tex_hover;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            exit(0);
    }
    else
        this->_quit_tex = this->_quit_tex_idle;
}

void Bomberman::Menu::handleInput(void)
{
    Raylib::Core::Input input;
    Vector2 mouse_position = input.getMousePosition();

    this->handle_solo_input(mouse_position);
    this->handle_multi_input(mouse_position);
    this->handle_quit_input(mouse_position);
}

void Bomberman::Menu::draw(Raylib::Core::Window* window, Bomberman::State* state)
{
    this->handleInput();
    this->_fond_tex->draw(0, 0, WHITE);
    this->_title_tex->draw(0, 0, WHITE);
    this->_solo_tex->draw(window->getWidth() - 575, 200, WHITE);
    this->_multi_tex->draw(window->getWidth() - 575, 350, WHITE);
    this->_quit_tex->draw(window->getWidth() - 575, 800, WHITE);
}

bool Bomberman::Menu::getHasMusicChange() {
    return _hasMusicChange;
}

void Bomberman::Menu::setHasMusicChange(bool hasMusicChange) {
    _hasMusicChange = hasMusicChange;
}
