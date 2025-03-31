/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Bomb.cpp
*/

#include "Bomb.hpp"
//#include <unistd.h>


Bomberman::Entities::Bomb::Bomb(Vector3 position) {
    _position = position;
    _timer = new Bomberman::Timer(3.0f);
    #if _WIN32
        Vector3 a = { 0.4f, 0.4f, 0.4f };
        _model =_model = new Raylib::Models::ModelB("..\\assets\\models\\bomb\\bomb", "..\\assets\\textures\\bomb\\bomb", position, a);
    #else
        _model =_model = new Raylib::Models::ModelB("assets/models/bomb/bomb", "assets/textures/bomb/bomb", position, (Vector3) {0.4f, 0.4f, 0.4f});
    #endif
}

Bomberman::Entities::Bomb::~Bomb() {
    this->_model->~ModelB();
}

Bomberman::Timer *Bomberman::Entities::Bomb::getTimer(void)
{
    return (this->_timer);
}

void Bomberman::Entities::Bomb::explode() {
    delete this;
}

bool Bomberman::Entities::Bomb::isExplosing(void) {
    return (this->explosing);
}

void Bomberman::Entities::Bomb::setExplode(bool value) {
    this->explosing = value;
}

void Bomberman::Entities::Bomb::scaleUp(void) {
    Raylib::Models::ModelB *tmp = this->getModel();

    tmp->getScale()->x += 0.0005;
    tmp->getScale()->y += 0.0005;
    tmp->getScale()->z += 0.0005;
}

Vector3 Bomberman::Entities::Bomb::getPosition(void)
{
    return (this->_position);
}

Raylib::Models::ModelB *Bomberman::Entities::Bomb::getModel() {
    return _model;
}