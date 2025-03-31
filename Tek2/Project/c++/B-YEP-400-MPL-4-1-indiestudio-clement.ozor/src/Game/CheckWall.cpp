/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-clement.ozor
** File description:
** CheckWall.cpp
*/

#include "Game.hpp"

bool Bomberman::Game::checkWallUp(Bomberman::Entities::Bomb *bomb, int range)
{
    for (auto &currWall : _entitiesGame.getWalls()) {
        if (bomb->getPosition().x + range == currWall->getPosition().x &&
        bomb->getPosition().z == currWall->getPosition().z)
            return (true);
    }
    return (false);
}

bool Bomberman::Game::checkWallDown(Bomberman::Entities::Bomb *bomb, int range)
{
    for (auto &currWall: _entitiesGame.getWalls()) {
        if (bomb->getPosition().x - range == currWall->getPosition().x &&
        bomb->getPosition().z == currWall->getPosition().z)
            return (true);
    }
    return (false);
}

bool Bomberman::Game::checkWallLeft(Bomberman::Entities::Bomb *bomb, int range)
{
    for (auto &currWall: _entitiesGame.getWalls()) {
        if (bomb->getPosition().x == currWall->getPosition().x &&
        bomb->getPosition().z - range == currWall->getPosition().z)
            return (true);
    }
    return (false);
}

bool Bomberman::Game::checkWallRight(Bomberman::Entities::Bomb *bomb, int range)
{
    for (auto &currWall : _entitiesGame.getWalls()) {
        if (bomb->getPosition().x == currWall->getPosition().x &&
        bomb->getPosition().z + range == currWall->getPosition().z)
            return (true);
    }
    return (false);
}

bool Bomberman::Game::checkPlayerUp(Bomberman::Entities::Bomb *bomb, int range)
{
    for (auto &currWall : _entitiesGame.getPlayers()) {
        if (bomb->getPosition().x + range == currWall->getPosition().x &&
            bomb->getPosition().z == currWall->getPosition().z)
            return (true);
    }
    return (false);
}

bool Bomberman::Game::checkPlayerDown(Bomberman::Entities::Bomb *bomb, int range)
{
    for (auto &currWall: _entitiesGame.getPlayers()) {
        if (bomb->getPosition().x - range == currWall->getPosition().x &&
            bomb->getPosition().z == currWall->getPosition().z)
            return (true);
    }
    return (false);
}

bool Bomberman::Game::checkPlayerLeft(Bomberman::Entities::Bomb *bomb, int range)
{
    for (auto &currWall: _entitiesGame.getPlayers()) {
        if (bomb->getPosition().x == currWall->getPosition().x &&
            bomb->getPosition().z - range == currWall->getPosition().z)
            return (true);
    }
    return (false);
}

bool Bomberman::Game::checkPlayerRight(Bomberman::Entities::Bomb *bomb, int range)
{
    for (auto &currWall : _entitiesGame.getPlayers()) {
        if (bomb->getPosition().x == currWall->getPosition().x &&
            bomb->getPosition().z + range == currWall->getPosition().z)
            return (true);
    }
    return (false);
}

void Bomberman::Game::detectDeath() {
    bool playerDead = true;
    bool Ai1Dead = true;
    bool Ai2Dead = true;
    bool Ai3Dead = true;

    for (auto &player : _entitiesGame.getPlayers()) {
        if (player->getId() == 0)
            playerDead = false;
        if (player->getId() == 1)
            Ai1Dead = false;
        if (player->getId() == 2)
            Ai2Dead = false;
        if (player->getId() == 3)
            Ai3Dead = false;
    }

    if (playerDead) {
        _menu->setHasMusicChange(false);
        this->_state = END_LOOSE_STATE;
    }
    if (Ai1Dead && Ai2Dead && Ai3Dead) {
        _menu->setHasMusicChange(false);
        this->_state = END_WIN_STATE;
    }
}


void Bomberman::Game::detectMultDeath() {
    bool player1Dead = true;
    bool player2Dead = true;
    bool Ai1Dead = true;
    bool Ai2Dead = true;

    for (auto &player : _entitiesGame.getPlayers()) {
        if (player->getId() == 0)
            player1Dead = false;
        if (player->getId() == 1)
            Ai1Dead = false;
        if (player->getId() == 2)
            player2Dead = false;
        if (player->getId() == 3)
            Ai2Dead = false;
    }

    if (player1Dead && !player2Dead && Ai1Dead && Ai2Dead) {
        _menu->setHasMusicChange(false);
        this->_state = END_WIN_STATE;
        this->_multWinState = MULT_END_WIN2_STATE;
    }
    if (!player1Dead && player2Dead && Ai1Dead && Ai2Dead) {
        _menu->setHasMusicChange(false);
        this->_state = END_WIN_STATE;
        this->_multWinState = MULT_END_WIN1_STATE;
    }
    if (player1Dead && player2Dead && (!Ai1Dead || !Ai2Dead)) {
        _menu->setHasMusicChange(false);
        this->_state = END_LOOSE_STATE;
    }
}