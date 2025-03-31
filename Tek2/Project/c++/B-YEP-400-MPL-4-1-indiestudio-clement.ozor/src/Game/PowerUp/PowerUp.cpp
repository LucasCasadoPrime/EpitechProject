/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** PowerUp
*/

#include "PowerUp.hpp"

Bomberman::PowerUp::PowerUp::PowerUp() {}

Bomberman::PowerUp::PowerUp::~PowerUp() {}

void Bomberman::PowerUp::PowerUp::addBomb(Vector3 position) {
    this->_bomb.push_back(new Bomb(position));
}

void Bomberman::PowerUp::PowerUp::addSpeed(Vector3 position) {
    this->_speed.push_back(new Speed(position));
}

void Bomberman::PowerUp::PowerUp::addRange(Vector3 position) {
    this->_range.push_back(new Range(position));
}

void Bomberman::PowerUp::PowerUp::addWallPass(Vector3 position) {
    this->_wallpass.push_back(new WallPass(position));
}

void Bomberman::PowerUp::PowerUp::addPowerUpRandom(Vector3 position) {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 10);
    int random = dist(rd);

    switch (random) {
    case 1:
        this->addBomb(position);
        break;
    case 2:
        this->addRange(position);
        break;
    case 3:
        this->addSpeed(position);
        break;
    case 4:
        this->addWallPass(position);
        break;
    }
}

void Bomberman::PowerUp::PowerUp::removeBomb(int position) {
    //    _sound->play();
    this->_bomb.erase(_bomb.begin() + position);
}

void Bomberman::PowerUp::PowerUp::removeSpeed(int position) {
    //    _sound->play();
    this->_speed.erase(_speed.begin() + position);
}

void Bomberman::PowerUp::PowerUp::removeRange(int position) {
    //    _sound->play();
    this->_range.erase(_range.begin() + position);
}

void Bomberman::PowerUp::PowerUp::removeWallPass(int position) {
    //    _sound->play();
    this->_wallpass.erase(_wallpass.begin() + position);
}

std::vector<Bomberman::PowerUp::Bomb*> Bomberman::PowerUp::PowerUp::getBomb() {
    return this->_bomb;
}

std::vector<Bomberman::PowerUp::Speed*> Bomberman::PowerUp::PowerUp::getSpeed() {
    return this->_speed;
}

std::vector<Bomberman::PowerUp::Range*> Bomberman::PowerUp::PowerUp::getRange() {
    return this->_range;
}

std::vector<Bomberman::PowerUp::WallPass*> Bomberman::PowerUp::PowerUp::getWallPass() {
    return this->_wallpass;
}

void Bomberman::PowerUp::PowerUp::draw() {
    Vector3 dro = { 0.0f, 0.0f, 0.0f };
    for (auto& it : this->_bomb)
        it->getModel()->drawEx(dro, 0.0f);
    for (auto& it : this->_range)
        it->getModel()->drawEx(dro, 0.0f);
    for (auto& it : this->_speed)
        it->getModel()->drawEx(dro, 0.0f);
    for (auto& it : this->_wallpass)
        it->getModel()->drawEx(dro, 0.0f);
}

void Bomberman::PowerUp::PowerUp::checkPlayer(Bomberman::Entities::Player*& player, Raylib::Audio::SoundB* sound) {
    Vector3 playerPosition = player->getPosition();
    float playerPositionX = (playerPosition.x - 5.0f) / 10;
    float playerPositionZ = (playerPosition.z - 5.0f) / 10;
    Vector3 powerUpPosition;
    float powerUpPositionX;
    float powerUpPositionZ;

    for (std::size_t i = 0; i < this->_bomb.size(); i++) {
        powerUpPosition = this->_bomb[i]->getPosition();
        powerUpPositionX = (powerUpPosition.x - 5.0f) / 10;
        powerUpPositionZ = (powerUpPosition.z - 5.0f) / 10;
        if (playerPositionX == powerUpPositionX && playerPositionZ == powerUpPositionZ) {
            sound->play();
            this->removeBomb(i);
            player->setBombNumber(player->getBombNumber() + 1);
        }
    }
    for (std::size_t i = 0; i < this->_range.size(); i++) {
        powerUpPosition = this->_range[i]->getPosition();
        powerUpPositionX = (powerUpPosition.x - 5.0f) / 10;
        powerUpPositionZ = (powerUpPosition.z - 5.0f) / 10;
        if (playerPositionX == powerUpPositionX && playerPositionZ == powerUpPositionZ) {
            sound->play();
            this->removeRange(i);
            player->setRange(player->getRange() + 1);
        }
    }
    for (std::size_t i = 0; i < this->_speed.size(); i++) {
        powerUpPosition = this->_speed[i]->getPosition();
        powerUpPositionX = (powerUpPosition.x - 5.0f) / 10;
        powerUpPositionZ = (powerUpPosition.z - 5.0f) / 10;
        if (playerPositionX == powerUpPositionX && playerPositionZ == powerUpPositionZ) {
            sound->play();
            this->removeSpeed(i);
            if (player->getSpeed() < 1.0f)
                player->setSpeed(player->getSpeed() + 0.5f);
        }
    }
    for (std::size_t i = 0; i < this->_wallpass.size(); i++) {
        powerUpPosition = this->_wallpass[i]->getPosition();
        powerUpPositionX = (powerUpPosition.x - 5.0f) / 10;
        powerUpPositionZ = (powerUpPosition.z - 5.0f) / 10;
        if (playerPositionX == powerUpPositionX && playerPositionZ == powerUpPositionZ) {
            sound->play();
            this->removeWallPass(i);
            player->setWallPass(true);
        }
    }
}