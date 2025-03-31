/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Box.cpp
*/

#include "Box.hpp"

Bomberman::Entities::Box::Box(Vector3 position, int id) {
    Vector3 win_shit = { 0.4f, 0.4f, 0.4f };
    _id = id;
    _position = position;
    #if _WIN32
        _model = new Raylib::Models::ModelB("..\\assets\\models\\box\\box", "..\\assets\\textures\\box\\box", position, win_shit);
    #else
        _model = new Raylib::Models::ModelB("assets/models/box/box", "assets/textures/box/box", position, (Vector3) {0.4f, 0.4f, 0.4f});
    #endif
}

Bomberman::Entities::Box::~Box() {
    this->getModel()->~ModelB();
}

Raylib::Models::ModelB *Bomberman::Entities::Box::getModel() {
    return _model;
}

int Bomberman::Entities::Box::getId(void)
{
    return (this->_id);
}

Vector3 Bomberman::Entities::Box::getPosition() {
    return _position;
}