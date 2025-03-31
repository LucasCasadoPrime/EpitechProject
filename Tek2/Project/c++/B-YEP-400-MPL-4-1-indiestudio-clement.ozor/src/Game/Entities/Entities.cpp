/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Entity.cpp
*/

#include "Entities.hpp"

Bomberman::Entities::Entities::Entities() {}

Bomberman::Entities::Entities::~Entities() {}

void Bomberman::Entities::Entities::addPlayer(Player *player) {
    _players.push_back(player);
}

void Bomberman::Entities::Entities::addWall(Wall *wall) {
    _walls.push_back(wall);
}

void Bomberman::Entities::Entities::addBox(Box *box) {
    _boxes.push_back(box);
}

void Bomberman::Entities::Entities::removePlayer(int position) {
    _players.erase(_players.begin() + position);
}

void Bomberman::Entities::Entities::removeWall(int position) {
    _walls.erase(_walls.begin() + position);
}

void Bomberman::Entities::Entities::removeBox(int position) {
    _boxes.erase(_boxes.begin() + position);
}

std::vector<Bomberman::Entities::Player *> Bomberman::Entities::Entities::getPlayers() {
    return _players;
}

std::vector<Bomberman::Entities::Wall *> Bomberman::Entities::Entities::getWalls() {
    return _walls;
}

std::vector<Bomberman::Entities::Box *> Bomberman::Entities::Entities::getBoxes() {
    return _boxes;
}

void Bomberman::Entities::Entities::destroy(void)
{
    for (auto &currBox: _boxes)
        currBox->~Box();
    _boxes.clear();
    for (auto &currWall: _walls)
        currWall->~Wall();
    _walls.clear();
    for (auto &currPlayer: _players)
        currPlayer->~Player();
    _players.clear();
}