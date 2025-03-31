/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Bomb
*/

#include "Bomb.hpp"

Bomberman::PowerUp::Bomb::Bomb(Vector3 position) {
    this->_position = position;
    #if _WIN32
    Vector3 a = { 3.0f, 3.0f, 3.0f };
        this->_model = new Raylib::Models::ModelB("..\\assets\\models\\cube\\cube", "..\\assets\\textures\\powerup\\bomb", position, a);
    #else
        this->_model = new Raylib::Models::ModelB("assets/models/cube/cube", "assets/textures/powerup/bomb", position, (Vector3) {3.0f, 3.0f, 3.0f});
    #endif
}
Bomberman::PowerUp::Bomb::~Bomb() {}

Raylib::Models::ModelB *Bomberman::PowerUp::Bomb::getModel() {
    return this->_model;
}

Vector3 Bomberman::PowerUp::Bomb::getPosition() {
    return this->_position;
}
