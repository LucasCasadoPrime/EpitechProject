/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Wall.cpp
*/

#include "Wall.hpp"

Bomberman::Entities::Wall::Wall(Vector3 position) {
    _position = position;
    #if _WIN32
    Vector3 a = { 5.0f, 5.0f, 5.0f };
        _model = new Raylib::Models::ModelB("..\\assets\\models\\brick\\brick", "..\\assets\\textures\\brick\\brick", position, a);
    #else
        _model = new Raylib::Models::ModelB("assets/models/brick/brick", "assets/textures/brick/brick", position, (Vector3) {5.0f, 5.0f, 5.0f});
    #endif
}

Bomberman::Entities::Wall::~Wall() {
    this->getModel()->~ModelB();
}

Raylib::Models::ModelB *Bomberman::Entities::Wall::getModel() {
    return _model;
}

Vector3 Bomberman::Entities::Wall::getPosition() {
    return _position;
}