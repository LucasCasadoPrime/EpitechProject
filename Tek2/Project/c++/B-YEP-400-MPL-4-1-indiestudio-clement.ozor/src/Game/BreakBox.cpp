/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-clement.ozor
** File description:
** breakBox.cpp
*/

#include "Game.hpp"

void Bomberman::Game::breakBoxUp(Bomberman::Entities::Bomb *bomb, int maxRange, std::vector<Bomberman::Entities::Bomb *> bombs)
{
    bool wallUp = false;
    float range = 10.0f;

    for (int tmp = 0; !wallUp && tmp < maxRange; tmp++, range += 10.0f) {
        for (auto &currBox: _entitiesGame.getBoxes()) {
            if (this->checkWallUp(bomb, range)) {
                wallUp = true;
                break;
            }
            if ((bomb->getPosition().x + range) == currBox->getPosition().x &&
                bomb->getPosition().z == currBox->getPosition().z) {
                _entitiesGame.removeBox(this->getBoxIndex(currBox->getId()));
                this->_powerUps.addPowerUpRandom(currBox->getPosition());
                _soundBoxBreak->play();
                break;
            }
        }
        for (auto &currBox: _entitiesGame.getPlayers()) {
            if ((bomb->getPosition().x + range) == currBox->getPosition().x &&
                bomb->getPosition().z == currBox->getPosition().z) {
                currBox->removeLife();
                if (currBox->getLife() <= 0) {
                    _entitiesGame.removePlayer(this->getPlayerIndex(currBox->getId()));
                    _soundPlayerDeath->play();
                }
                break;
            }
        }
        for (std::size_t i = 0; i < bombs.size(); i++) {
            if ((bomb->getPosition().x + range) == bombs[i]->getPosition().x &&
                bomb->getPosition().z == bombs[i]->getPosition().z) {
                bombs[i]->getTimer()->setTimer(0.0f);
                break;
            }
        }
    }
}

void Bomberman::Game::breakBoxDown(Bomberman::Entities::Bomb *bomb, int maxRange, std::vector<Bomberman::Entities::Bomb *> bombs)
{
    bool wallDown = false;
    float range = 10.0f;

    for (int tmp = 0; !wallDown && tmp < maxRange; tmp++, range += 10.0f) {
        for (auto &currBox: _entitiesGame.getBoxes()) {
            if (this->checkWallDown(bomb, range)) {
                wallDown = true;
                break;
            }
            if ((bomb->getPosition().x - range) == currBox->getPosition().x &&
            bomb->getPosition().z == currBox->getPosition().z) {
                _entitiesGame.removeBox(this->getBoxIndex(currBox->getId()));
                this->_powerUps.addPowerUpRandom(currBox->getPosition());
                _soundBoxBreak->play();
                break;
            }
        }
        for (auto &currBox: _entitiesGame.getPlayers()) {
            if ((bomb->getPosition().x - range) == currBox->getPosition().x &&
                bomb->getPosition().z == currBox->getPosition().z) {
                currBox->removeLife();
                if (currBox->getLife() <= 0) {
                    _entitiesGame.removePlayer(this->getPlayerIndex(currBox->getId()));
                    _soundPlayerDeath->play();
                }
                break;
            }
        }
        for (std::size_t i = 0; i < bombs.size(); i++) {
            if ((bomb->getPosition().x - range) == bombs[i]->getPosition().x &&
            bomb->getPosition().z == bombs[i]->getPosition().z) {
                bombs[i]->getTimer()->setTimer(0.0f);
                break;
            }
        }
    }
}

void Bomberman::Game::breakBoxLeft(Bomberman::Entities::Bomb *bomb, int maxRange, std::vector<Bomberman::Entities::Bomb *> bombs)
{
    bool wallLeft = false;
    float range = 10.0f;

    for (int tmp = 0; !wallLeft && tmp < maxRange; tmp++, range += 10.0f) {
        for (auto &currBox: _entitiesGame.getBoxes()) {
            if (this->checkWallLeft(bomb, range)) {
                wallLeft = true;
                break;
            }
            if (bomb->getPosition().x == currBox->getPosition().x &&
            (bomb->getPosition().z - range) == currBox->getPosition().z) {
                _entitiesGame.removeBox(this->getBoxIndex(currBox->getId()));
                this->_powerUps.addPowerUpRandom(currBox->getPosition());
                _soundBoxBreak->play();
                break;
            }
        }
        for (auto &currBox: _entitiesGame.getPlayers()) {
            if (bomb->getPosition().x == currBox->getPosition().x &&
                (bomb->getPosition().z - range) == currBox->getPosition().z) {
                currBox->removeLife();
                if (currBox->getLife() <= 0) {
                    _entitiesGame.removePlayer(this->getPlayerIndex(currBox->getId()));
                    _soundPlayerDeath->play();
                }
                break;
            }
        }
        for (std::size_t i = 0; i < bombs.size(); i++) {
            if (bomb->getPosition().x == bombs[i]->getPosition().x &&
            (bomb->getPosition().z - range) == bombs[i]->getPosition().z) {
                bombs[i]->getTimer()->setTimer(0.0f);
                break;
            }
        }
    }
}

void Bomberman::Game::breakBoxRight(Bomberman::Entities::Bomb *bomb, int maxRange, std::vector<Bomberman::Entities::Bomb *> bombs)
{
    bool wallRight = false;
    float range = 10.0f;

    for (int tmp = 0; !wallRight && tmp < maxRange; tmp++, range += 10.0f) {
        for (auto &currBox : _entitiesGame.getBoxes()) {
            if (this->checkWallRight(bomb, range)) {
                wallRight = true;
                break;
            }
            if (bomb->getPosition().x == currBox->getPosition().x &&
            (bomb->getPosition().z + range) == currBox->getPosition().z) {
                _entitiesGame.removeBox(this->getBoxIndex(currBox->getId()));
                this->_powerUps.addPowerUpRandom(currBox->getPosition());
                _soundBoxBreak->play();
                break;
            }
        }
        for (auto &currBox : _entitiesGame.getPlayers()) {
            if (bomb->getPosition().x == currBox->getPosition().x &&
                (bomb->getPosition().z + range) == currBox->getPosition().z) {
                currBox->removeLife();
                if (currBox->getLife() <= 0) {
                    _entitiesGame.removePlayer(this->getPlayerIndex(currBox->getId()));
                    _soundPlayerDeath->play();
                }
                break;
            }
        }
        for (std::size_t i = 0; i < bombs.size(); i++) {
            if (bomb->getPosition().x == bombs[i]->getPosition().x &&
            (bomb->getPosition().z + range) == bombs[i]->getPosition().z) {
                bombs[i]->getTimer()->setTimer(0.0f);
                break;
            }
        }
    }
}

void Bomberman::Game::breakBox(Bomberman::Entities::Player *player) {
    int maxRange = player->getRange();
    std::vector<Bomberman::Entities::Bomb *> bombs = player->getBombs();

    for (auto &bomb: bombs) {
        if (bomb->isExplosing()) {
            if (player->getPosition().x == bomb->getPosition().x && player->getPosition().z == bomb->getPosition().z) {
                player->removeLife();
                if (player->getLife() <= 0) {
                    _entitiesGame.removePlayer(this->getPlayerIndex(player->getId()));
                    _soundPlayerDeath->play();
                }
            }
            this->breakBoxUp(bomb, maxRange, bombs);
            this->breakBoxDown(bomb, maxRange, bombs);
            this->breakBoxLeft(bomb, maxRange, bombs);
            this->breakBoxRight(bomb, maxRange, bombs);
        }
    }
}