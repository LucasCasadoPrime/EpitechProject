/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** Speed
*/

#include "Speed.hpp"

Bomberman::PowerUp::Speed::Speed(Vector3 position) {
    this->_position = position;
#if _WIN32
    Vector3 didier = { 3.0f, 3.0f, 3.0f };
    this->_model = new Raylib::Models::ModelB("..\\assets\\models\\cube\\cube", "..\\assets\\textures\\powerup\\speed", position, didier);
#else
    this->_model = new Raylib::Models::ModelB("assets/models/cube/cube", "assets/textures/powerup/speed", position, (Vector3) { 3.0f, 3.0f, 3.0f });
#endif
}
Bomberman::PowerUp::Speed::~Speed() {}

Raylib::Models::ModelB* Bomberman::PowerUp::Speed::getModel() {
    return this->_model;
}

Vector3 Bomberman::PowerUp::Speed::getPosition() {
    return this->_position;
}