/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** pacman
*/

#include "pacman.hpp"

namespace arcade {
    pacman::pacman() {}
    pacman::~pacman() {}
    void pacman::init() {}
    std::vector<std::pair<entitiesType, entities *>> pacman::runtime(int key, int &_game, bool &_running) {
        std::vector<std::pair<entitiesType, entities *>> ent;
        text *title = new text();
        title->scale = 45;
        title->color = {169, 77, 255};
        title->font = "assets/menu/font.otf";
        title->pos = {0, 10};
        title->text = "PACMAN";
        ent.push_back(std::pair<entitiesType, entities*>(text_t, title));
        return (ent);
    }
    std::string pacman::getName() {return "pacman";}
}

extern "C" arcade::pacman* getGame() {
    return (new arcade::pacman());
}