/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Player.cpp
*/

#include "Player.hpp"

Bomberman::Entities::Player::Player(int id, std::string texturepath, Vector3 position, float rotation, Vector3 rotationAxis)
{
    _id = id;
    _position = position;
    _rotation = rotation;
#if _WIN32
    Vector3 playouse = { 1.0f, 1.0f, 1.0f };
    _model = new Raylib::Models::ModelB("..\\assets\\models\\character\\character", "..\\assets\\textures\\character\\blue1", position, playouse);
#else
    _model = new Raylib::Models::ModelB("assets/models/character/character", texturepath, position, (Vector3) { 1.0f, 1.0f, 1.0f });
#endif
    _rotationAxis = rotationAxis;
    _timer = new Bomberman::Timer(1.0f);
}

Bomberman::Entities::Player::~Player() {
    this->getModel()->~ModelB();
}

int Bomberman::Entities::Player::getId() {
    return _id;
}

Raylib::Models::ModelB* Bomberman::Entities::Player::getModel() {
    return _model;
}

Vector3 Bomberman::Entities::Player::getPosition() {
    return _position;
}

float Bomberman::Entities::Player::getRotation() {
    return _rotation;
}

void Bomberman::Entities::Player::setId(int id) {
    _id = id;
}

void Bomberman::Entities::Player::setModel(Raylib::Models::ModelB* model) {
    _model = model;
}

void Bomberman::Entities::Player::setPosition(Vector3 position) {
    _position = position;
    _model->setPosition(position);
}

void Bomberman::Entities::Player::setRotation(float rotation) {
    _rotation = rotation;
}

Vector3 Bomberman::Entities::Player::getRotationAxis() {
    return _rotationAxis;
}

void Bomberman::Entities::Player::setRotationAxis(Vector3 rotationAxis) {
    _rotationAxis = rotationAxis;
}

void Bomberman::Entities::Player::placeBomb(Raylib::Audio::SoundB* sound) {
    if (this->_bombs.size() < this->_bombsNumber) {
        sound->play();
        _bombs.push_back(new Bomberman::Entities::Bomb(_position));
    }
}

std::vector<Bomberman::Entities::Bomb*> Bomberman::Entities::Player::getBombs() {
    return _bombs;
}

int Bomberman::Entities::Player::getBombNumber() {
    return this->_bombsNumber;
}

void Bomberman::Entities::Player::setBombNumber(int value) {
    this->_bombsNumber = value;
}

float Bomberman::Entities::Player::getSpeed() {
    return this->_speed;
}

void Bomberman::Entities::Player::setSpeed(float value) {
    this->_speed = value;
}

int Bomberman::Entities::Player::getRange(void)
{
    return (this->_range);
}

void Bomberman::Entities::Player::setRange(int range)
{
    this->_range = range;
}

void Bomberman::Entities::Player::removeBomb(int position) {
    this->_bombs.erase(_bombs.begin() + position);
}

void Bomberman::Entities::Player::move(Direction direction, std::vector<Player*> players, std::vector<Wall*> walls, std::vector<Box*> boxes, Raylib::Audio::SoundB* sound) {
    bool canMove = this->canMove(direction, players, walls, boxes);
    if (!canMove) {
        _hasMoved = true;
        _targetPos = _position;
    }

    if (direction == Direction::UP) {
        this->setRotation(90.0f);
        if (!canMove)
            return;
        if (!_isSoundPlayed) {
            sound->play();
            _isSoundPlayed = true;
        }
        this->moveUp();
    }
    else if (direction == Direction::DOWN) {
        this->setRotation(270.0f);
        if (!canMove)
            return;
        if (!_isSoundPlayed) {
            sound->play();
            _isSoundPlayed = true;
        }
        this->moveDown();
    }
    else if (direction == Direction::LEFT) {
        this->setRotation(180.0f);
        if (!canMove)
            return;
        if (!_isSoundPlayed) {
            sound->play();
            _isSoundPlayed = true;
        }
        this->moveLeft();
    }
    else if (direction == Direction::RIGHT) {
        this->setRotation(0.0f);
        if (!canMove)
            return;
        if (!_isSoundPlayed) {
            sound->play();
            _isSoundPlayed = true;
        }
        this->moveRight();
    }
}

bool Bomberman::Entities::Player::canMove(Direction direction, std::vector<Player*> players, std::vector<Wall*> walls, std::vector<Box*> boxes) {
    if (direction == Direction::UP) {
        for (auto& currPlayer : players) {
            if (this->getId() != currPlayer->getId()) {
                if (this->isFloatEqual(this->getPosition().x + 10.0f, currPlayer->getPosition().x, 0.1f) &&
                    this->isFloatEqual(this->getPosition().z, currPlayer->getPosition().z, 0.1f))
                    return (false);
            }
        }
        if (!this->getWallPass()) {
            for (auto& currBox : boxes) {
                if (this->getPosition().x + 10.0f == currBox->getPosition().x &&
                    this->getPosition().z == currBox->getPosition().z)
                    return (false);
            }
        }
        for (auto& currWall : walls) {
            if (this->getPosition().x + 10.0f == currWall->getPosition().x && this->getPosition().z == currWall->getPosition().z)
                return (false);
        }
        for (auto& bomb : this->_bombs) {
            if (this->getPosition().x + 10.0f == bomb->getPosition().x && this->getPosition().z == bomb->getPosition().z)
                return (false);
        }
    }
    if (direction == Direction::DOWN) {
        for (auto& currPlayer : players) {
            if (this->getId() != currPlayer->getId()) {
                if (this->getPosition().x - 10.0f == currPlayer->getPosition().x && this->getPosition().z == currPlayer->getPosition().z)
                    return false;
            }
        }
        if (!this->getWallPass()) {
            for (auto& currBox : boxes) {
                if (this->getPosition().x - 10.0f == currBox->getPosition().x &&
                    this->getPosition().z == currBox->getPosition().z)
                    return false;
            }
        }
        for (auto& currWall : walls) {
            if (this->getPosition().x - 10.0f == currWall->getPosition().x && this->getPosition().z == currWall->getPosition().z)
                return false;
        }
        for (auto& bomb : this->_bombs) {
            if (this->getPosition().x - 10.0f == bomb->getPosition().x && this->getPosition().z == bomb->getPosition().z)
                return false;
        }
    }
    if (direction == Direction::LEFT) {
        for (auto& currPlayer : players) {
            if (this->getId() != currPlayer->getId()) {
                if (this->getPosition().x == currPlayer->getPosition().x && this->getPosition().z - 10.0f == currPlayer->getPosition().z)
                    return false;
            }
        }
        if (!this->getWallPass()) {
            for (auto& currBox : boxes) {
                if (this->getPosition().x == currBox->getPosition().x &&
                    this->getPosition().z - 10.0f == currBox->getPosition().z)
                    return false;
            }
        }
        for (auto& currWall : walls) {
            if (this->getPosition().x == currWall->getPosition().x && this->getPosition().z - 10.0f == currWall->getPosition().z)
                return false;
        }
        for (auto& bomb : this->_bombs) {
            if (this->getPosition().x == bomb->getPosition().x && this->getPosition().z - 10.0f == bomb->getPosition().z)
                return false;
        }
    }
    if (direction == Direction::RIGHT) {
        for (auto& currPlayer : players) {
            if (this->getId() != currPlayer->getId()) {
                if (this->getPosition().x == currPlayer->getPosition().x && this->getPosition().z + 10.0f == currPlayer->getPosition().z)
                    return false;
            }
        }
        if (!this->getWallPass()) {
            for (auto& currBox : boxes) {
                if (this->getPosition().x == currBox->getPosition().x &&
                    this->getPosition().z + 10.0f == currBox->getPosition().z)
                    return false;
            }
        }
        for (auto& currWall : walls) {
            if (this->getPosition().x == currWall->getPosition().x && this->getPosition().z + 10.0f == currWall->getPosition().z)
                return false;
        }
        for (auto& bomb : this->_bombs) {
            if (this->getPosition().x == bomb->getPosition().x && this->getPosition().z + 10.0f == bomb->getPosition().z)
                return false;
        }
    }
    return (true);
}

void Bomberman::Entities::Player::moveUp() {
    Vector3 movupe = { std::fabs(this->getPosition().x + 0.5f), this->getPosition().y, this->getPosition().z };
    this->setPosition(movupe);
}

void Bomberman::Entities::Player::moveDown() {
    Vector3 movdown = { std::fabs(this->getPosition().x - 0.5f), this->getPosition().y, this->getPosition().z };
    this->setPosition(movdown);
}

void Bomberman::Entities::Player::moveLeft() {
    Vector3 movelefte = { this->getPosition().x, this->getPosition().y, std::fabs(this->getPosition().z - 0.5f) };
    this->setPosition(movelefte);
}

void Bomberman::Entities::Player::moveRight() {
    Vector3 moverighte = { this->getPosition().x, this->getPosition().y, std::fabs(this->getPosition().z + 0.5f) };
    this->setPosition(moverighte);
}

Bomberman::Timer* Bomberman::Entities::Player::getTimer() {
    return _timer;
}

void Bomberman::Entities::Player::update(std::vector<Player*> players, std::vector<Wall*> walls, std::vector<Box*> boxes, Raylib::Audio::SoundB* sound) {
    //    std::cout << "Player " << getId() << " : " << _position.x << ", " << _position.z << " | " << _targetPos.x << ", " << _targetPos.z  << std::endl;
    if (this->isFloatEqual(_position.x, _targetPos.x) && this->isFloatEqual(_position.z, _targetPos.z)) {
        _isMoving = false;
        _hasMoved = true;
        _isSoundPlayed = false;
    }
    else if (_position.x < _targetPos.x && isFloatEqual(_position.z, _targetPos.z))
        this->move(Direction::UP, players, walls, boxes, sound);
    else if (_position.x > _targetPos.x && isFloatEqual(_position.z, _targetPos.z))
        this->move(Direction::DOWN, players, walls, boxes, sound);
    else if (this->isFloatEqual(_position.x, _targetPos.x) && _position.z < _targetPos.z)
        this->move(Direction::RIGHT, players, walls, boxes, sound);
    else if (this->isFloatEqual(_position.x, _targetPos.x) && _position.z > _targetPos.z)
        this->move(Direction::LEFT, players, walls, boxes, sound);
}

void Bomberman::Entities::Player::setTargetPos(Vector3 pos) {
    _targetPos = pos;
}

bool Bomberman::Entities::Player::getIsMoving() {
    return _isMoving;
}

void Bomberman::Entities::Player::setIsMoving(bool isMoving) {
    _isMoving = isMoving;
}

bool Bomberman::Entities::Player::isFloatEqual(float a, float b, float epsilon) {
    return (std::fabs(a - b) < epsilon);
}

void Bomberman::Entities::Player::setHasMoved(bool hasMoved) {
    _hasMoved = hasMoved;
}

bool Bomberman::Entities::Player::getHasMoved() {
    return _hasMoved;
}

void Bomberman::Entities::Player::resetTimer() {
    delete _timer;
    _timer = new Bomberman::Timer(1.0f);
}

Vector3 Bomberman::Entities::Player::getTargetPosition() {
    return _targetPos;
}

void Bomberman::Entities::Player::setWallPass(bool wallPass) {
    _wallPass = wallPass;
}

bool Bomberman::Entities::Player::getWallPass() {
    return _wallPass;
}

int Bomberman::Entities::Player::getLife() {
    return _life;
}

void Bomberman::Entities::Player::removeLife() {
    _life--;
}
