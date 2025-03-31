/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** PowerUp
*/

#ifndef POWERUP_HPP_
#define POWERUP_HPP_

#include "Essentials.hpp"
#include "Raylib.hpp"
#include "Range.hpp"
#include "Bomb.hpp"
#include "Speed.hpp"
#include "WallPass.hpp"
#if _WIN32
#include "..\Entities\Player.hpp"
#else
#include "../Entities/Player.hpp"
#endif

namespace Bomberman {
    namespace PowerUp {
        class PowerUp {
        public:
            PowerUp();
            ~PowerUp();
            void addBomb(Vector3);
            void addSpeed(Vector3);
            void addRange(Vector3);
            void addWallPass(Vector3);
            void addPowerUpRandom(Vector3);
            void removeBomb(int);
            void removeSpeed(int);
            void removeRange(int);
            void removeWallPass(int);
            std::vector<Bomb*> getBomb();
            std::vector<Speed*> getSpeed();
            std::vector<Range*> getRange();
            std::vector<WallPass*> getWallPass();
            void draw();
            void checkPlayer(Bomberman::Entities::Player*&, Raylib::Audio::SoundB* sound);

        private:
            std::vector<Range*> _range;
            std::vector<Speed*> _speed;
            std::vector<Bomb*> _bomb;
            std::vector<WallPass*> _wallpass;
            Raylib::Audio::SoundB* _sound;
        };
    }
}

#endif /* !POWERUP_HPP_ */