/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Game.hpp
*/

#ifndef BOMBERMAN_GAME_HPP
#define BOMBERMAN_GAME_HPP

#include "Essentials.hpp"
#include "Raylib.hpp"
#include "Menu.hpp"
#include "Timer.hpp"
#if _WIN32
    #include "Entities\Entities.hpp"
    #include "PowerUp\PowerUp.hpp"
    #include "..\Map\Map.hpp"
    #include "Entities\Player.hpp"
    #include "Entities\Bomb.hpp"
    #include "SaveAndLoad.hpp"
#else
    #include "Entities/Entities.hpp"
    #include "PowerUp/PowerUp.hpp"
    #include "Entities/Player.hpp"
    #include "Entities/Bomb.hpp"
    #include "SaveAndLoad.hpp"
    #include "../Map/Map.hpp"
#endif

namespace Bomberman {
    class Entity {
        public:
            Raylib::Models::ModelB *getModel(void);
            int getId();
            Entity(Raylib::Models::ModelB *model, int id);
            ~Entity();

        private:
            int _id;
            Raylib::Models::ModelB *_model;
    };

    class Game {
        public:
            Game();
            ~Game();
            void run();
            void handleInput(void);
            void handlePauseEndInput(Vector2 mouse_position);
            void drawSoloGame(void);
            void drawMultGame(void);
            void soloGameLoop(void);
            void updateSoloLoop(void);
            void updatePlayers(void);
            void multGameLoop(void);
            void handleSoloInput(void);
            void handleMultInput(void);
            void drawPause(void);
            void drawWinEnd(void);
            void drawLooseEnd(void);
            void createMapObjects(void);
            void soloAi();
            void multAi();
            void soloLoadModels(void);
            void breakBox(Bomberman::Entities::Player *player);
            void breakBoxUp(Bomberman::Entities::Bomb *bomb, int maxRange, std::vector<Bomberman::Entities::Bomb *> bombs);
            void breakBoxDown(Bomberman::Entities::Bomb *bomb, int maxRange, std::vector<Bomberman::Entities::Bomb *> bombs);
            void breakBoxLeft(Bomberman::Entities::Bomb *bomb, int maxRange, std::vector<Bomberman::Entities::Bomb *> bombs);
            void breakBoxRight(Bomberman::Entities::Bomb *bomb, int maxRange, std::vector<Bomberman::Entities::Bomb *> bombs);
            int getBoxIndex(int id);
            int getPlayerIndex(int id);
            bool checkWallUp(Bomberman::Entities::Bomb *bomb, int range);
            bool checkWallDown(Bomberman::Entities::Bomb *bomb, int range);
            bool checkWallLeft(Bomberman::Entities::Bomb *bomb, int range);
            bool checkWallRight(Bomberman::Entities::Bomb *bomb, int range);
            bool checkPlayerUp(Bomberman::Entities::Bomb *bomb, int range);
            bool checkPlayerDown(Bomberman::Entities::Bomb *bomb, int range);
            bool checkPlayerLeft(Bomberman::Entities::Bomb *bomb, int range);
            bool checkPlayerRight(Bomberman::Entities::Bomb *bomb, int range);
            void detectDeath();
            void detectMultDeath();

        private:
            void init();
            void draw();
            Bomberman::Menu *_menu = nullptr;
            Bomberman::State _state = MENU_STATE;
            Bomberman::State _currGameState;
            Bomberman::State _multWinState;
            Bomberman::Map _map;
            Raylib::Core::Window *_window = nullptr;
            Raylib::Core::Draw _draw;
            Raylib::Models::Draw _drawM;
            Raylib::Core::CameraB *_camera = nullptr;
            Raylib::Texts::Text *_HUDPlayer1Txt = nullptr;
            Raylib::Texts::Text *_HUDPlayer2Txt = nullptr;
            Raylib::Texts::Text *_HUDAi1Txt = nullptr;
            Raylib::Texts::Text *_HUDAi2Txt = nullptr;
            Raylib::Texts::Text *_HUDAi3Txt = nullptr;
            Raylib::Texts::Text *_pauseTxt = nullptr;
            Raylib::Texts::Text *_pauseTxtHelp = nullptr;
            Raylib::Texts::Text *_WinTxt = nullptr;
            Raylib::Texts::Text *_Win1Txt = nullptr;
            Raylib::Texts::Text *_Win2Txt = nullptr;
            Raylib::Texts::Text *_LooseTxt = nullptr;
            Raylib::Texts::Text *_EndTxtHelp = nullptr;
            Raylib::Texture::Tex *_ReturnBtn = nullptr;
            Raylib::Texture::Tex *_ReturnTexIdle = nullptr;
            Raylib::Texture::Tex *_ReturnTexHover = nullptr;
            Entities::Entities _entitiesGame;
            PowerUp::PowerUp _powerUps;
            bool _soloSelected = false;
            bool _multSelected = false;
            Raylib::Audio::Audio _audio;
            Raylib::Audio::SoundB *_soundBombExplode;
            Raylib::Audio::SoundB *_soundBombPlace;
            Raylib::Audio::SoundB *_soundBoxBreak;
            Raylib::Audio::SoundB *_soundFootsteps;
            Raylib::Audio::SoundB *_soundPlayerDeath;
            Raylib::Audio::SoundB *_soundPowerUpTake;
            Raylib::Audio::MusicB *_music = nullptr;
            bool _hasMusicChange = false;
            Raylib::Core::Input _input;
            SaveAndLoad _save;
            Raylib::Models::ModelB *_ground = nullptr;
    };
}

#endif
