/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** menu
*/

#include "menu.hpp"

namespace arcade {
    menu::menu() {}
    menu::~menu() {}

    void menu::init() {}

    std::string menu::getName() {return "Menu";}

    std::vector<std::pair<entitiesType, entities *>> menu::runtime(int key, int &_game, bool &_running) {
        std::vector<std::pair<entitiesType, entities *>> ent;
        static float cursor_y = 325;
        static int pos = 2;
        if (key == DOWN_ARROW && cursor_y + 30 <= 385)
            cursor_y += 30;
        if (key == UP_ARROW && cursor_y - 30 >= 325)
            cursor_y -= 30;
        if (key == RETURN) {
            if (cursor_y == 325) {
                _game -= 1;
                return(ent);
            }
            if (cursor_y == 355) {
                _game -= 2;
                return(ent);
            }
            if (cursor_y == 385) {
                _running = false;
                return(ent);
            }
        }
        sprite *background = new sprite();
        background->texturePath = "assets/menu/menu.png";
        background->scale = 1;
        background->symbol = ' ';
        background->pos = {0.0, 0.0};
        ent.push_back(std::pair<entitiesType, entities*>(sprite_t, background));
        sprite *cursor = new sprite();
        cursor->texturePath = "assets/menu/cursor.png";
        cursor->scale = 1;
        cursor->symbol = '>';
        cursor->pos = {450.0, cursor_y};
        ent.push_back(std::pair<entitiesType, entities*>(sprite_t, cursor));
        text *nibbler_title = new text();
        nibbler_title->scale = 20;
        nibbler_title->color = {255, 111, 0};
        nibbler_title->font = "assets/menu/font.otf";
        nibbler_title->pos = {495, 325};
        nibbler_title->text = "Nibbler";
        ent.push_back(std::pair<entitiesType, entities*>(text_t, nibbler_title));
        text *pacman_title = new text();
        pacman_title->scale = 20;
        pacman_title->color = {239, 255, 0};
        pacman_title->font = "assets/menu/font.otf";
        pacman_title->pos = {495, 355};
        pacman_title->text = "Pacman";
        ent.push_back(std::pair<entitiesType, entities*>(text_t, pacman_title));
        text *exit_title = new text();
        exit_title->scale = 20;
        exit_title->color = {169, 77, 255};
        exit_title->font = "assets/menu/font.otf";
        exit_title->pos = {495, 385};
        exit_title->text = "Exit";
        ent.push_back(std::pair<entitiesType, entities*>(text_t, exit_title));
        text *title = new text();
        title->scale = 45;
        title->color = {169, 77, 255};
        title->font = "assets/menu/font.otf";
        title->pos = {430, 0};
        title->text = " arcade";
        ent.push_back(std::pair<entitiesType, entities*>(text_t, title));
        text *key_settings = new text();
        key_settings->scale = 15;
        key_settings->color = {255, 255, 255};
        key_settings->font = "assets/menu/font.otf";
        key_settings->pos = {0, 700};
        key_settings->text = "F1/F2 : Change graphical library    F5/F6 : Change games";
        ent.push_back(std::pair<entitiesType, entities*>(text_t, key_settings));
        return (ent);
    }
}

extern "C" arcade::menu* getGame() {
    return (new arcade::menu());
}