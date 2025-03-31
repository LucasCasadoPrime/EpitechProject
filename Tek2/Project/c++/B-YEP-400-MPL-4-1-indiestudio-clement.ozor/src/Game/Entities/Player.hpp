/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Player.hpp
*/

#ifndef BOMBERMAN_PLAYER_HPP
#define BOMBERMAN_PLAYER_HPP

#include "Raylib.hpp"
#include "Bomb.hpp"
#include "Wall.hpp"
#include "Box.hpp"

namespace Bomberman {
    namespace Entities {
        enum Direction {
            UP,
            DOWN,
            LEFT,
            RIGHT
        };

        class Player {
        public:
            Player(int id, std::string texturepath, Vector3 position, float rotation, Vector3 rotationAxis);
            ~Player();
            void setId(int id);
            int getId();
            int getRange(void);
            void setRange(int range);
            void setModel(Raylib::Models::ModelB* model);
            Raylib::Models::ModelB* getModel();
            void setPosition(Vector3 position);
            Vector3 getPosition();
            void setRotation(float rotation);
            float getRotation();
            void setRotationAxis(Vector3 rotationAxis);
            Vector3 getRotationAxis();
            void placeBomb(Raylib::Audio::SoundB* sound);
            std::vector<Bomb*> getBombs();
            void removeBomb(int);
            int getBombNumber();
            void setBombNumber(int);
            float getSpeed();
            void setSpeed(float);
            void move(Direction direction, std::vector<Player*> players, std::vector<Wall*> walls, std::vector<Box*> boxes, Raylib::Audio::SoundB* sound);
            void update(std::vector<Player*> players, std::vector<Wall*> walls, std::vector<Box*> boxes, Raylib::Audio::SoundB* sound);
            void setTargetPos(Vector3 pos);
            void setIsMoving(bool isMoving);
            bool getIsMoving();
            void setHasMoved(bool hasMoved);
            bool getHasMoved();
            Bomberman::Timer* getTimer();
            void resetTimer();
            Vector3 getTargetPosition();
            void setWallPass(bool wallPass);
            bool getWallPass();
            int getLife();
            void removeLife();

        private:
            bool canMove(Direction direction, std::vector<Player*> players, std::vector<Wall*> walls, std::vector<Box*> boxes);
            void moveUp();
            void moveDown();
            void moveLeft();
            void moveRight();
            bool isFloatEqual(float a, float b, float epsilon = 0.1f);

            int _id;
            int _range = 1;
            int _bombsNumber = 1;
            float _speed = 0.5f;
            Raylib::Models::ModelB* _model;
            Vector3 _position;
            float _rotation;
            Vector3 _rotationAxis;
            std::vector<Bomb*> _bombs;
            Bomberman::Timer* _timer;
            bool _isMoving = false;
            bool _hasMoved = true;
            Vector3 _targetPos;
            bool _isSoundPlayed = false;
            bool _wallPass = false;
            int _life = 3;
        };
    }
}

#endif