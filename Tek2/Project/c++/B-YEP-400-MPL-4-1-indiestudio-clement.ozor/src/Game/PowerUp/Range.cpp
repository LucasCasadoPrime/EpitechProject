/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Range
*/

#include "Range.hpp"

Bomberman::PowerUp::Range::Range(Vector3 position) {
    this->_position = position;
#if _WIN32
    Vector3 rangerover = { 3.0f, 3.0f, 3.0f };
    this->_model = new Raylib::Models::ModelB("..\\assets\\models\\cube\\cube", "..\\assets\\textures\\powerup\\fire", position, rangerover);
#else
    this->_model = new Raylib::Models::ModelB("assets/models/cube/cube", "assets/textures/powerup/fire", position, (Vector3) { 3.0f, 3.0f, 3.0f });
#endif
}
Bomberman::PowerUp::Range::~Range() {}

Raylib::Models::ModelB* Bomberman::PowerUp::Range::getModel() {
    return this->_model;
}

Vector3 Bomberman::PowerUp::Range::getPosition() {
    return this->_position;
}