/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** WallPass
*/

#include "WallPass.hpp"

Bomberman::PowerUp::WallPass::WallPass(Vector3 position) {
    this->_position = position;
#if _WIN32
    Vector3 wallpasse = {
        3.0f,
        3.0f,
        3.0f
    };
    this->_model = new Raylib::Models::ModelB("..\\assets\\models\\cube\\cube", "..\\assets\\textures\\powerup\\wallpass", position, wallpasse);
#else
    this->_model = new Raylib::Models::ModelB("assets/models/cube/cube", "assets/textures/powerup/wallpass", position, (Vector3) { 3.0f, 3.0f, 3.0f });
#endif
}
Bomberman::PowerUp::WallPass::~WallPass() {}

Raylib::Models::ModelB* Bomberman::PowerUp::WallPass::getModel() {
    return this->_model;
}

Vector3 Bomberman::PowerUp::WallPass::getPosition() {
    return this->_position;
}