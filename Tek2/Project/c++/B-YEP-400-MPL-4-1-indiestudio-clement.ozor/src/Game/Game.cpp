/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Game.cpp
*/

#include "Game.hpp"
#include "raylib.h"

Bomberman::Game::Game() {
    Bomberman::Game::init();
}

Bomberman::Game::~Game() = default;

void Bomberman::Game::init() {
    Vector3 a = { -40.0f, 150.0f, 75.0f };
    Vector3 b = { 45.0f, 0.0f, 75.0f };
    Vector3 c = { 0.0f, 1.6f, 0.0f };
    Vector3 d = { 50.0f, 0.0f, 50.0f };
    Vector3 e = { 40.0f, 40.0f, 40.0f };

    #if _WIN32
        Raylib::Texture::Img ReturnIdle("..\\assets\\images\\menu\\Return_idle.png");
        Raylib::Texture::Img ReturnHover("..\\assets\\images\\menu\\Return_selected.png");
    #else
        Raylib::Texture::Img ReturnIdle("assets/images/menu/Return_idle.png");
        Raylib::Texture::Img ReturnHover("assets/images/menu/Return_selected.png");
    #endif

    _window = new Raylib::Core::Window(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, "Bomberman");
    Raylib::Core::Monitor monitor;
    _window->setSize(monitor.getWidth(), monitor.getHeight());
    _window->setPosition(0, 0);
    #if _WIN32
        _window->setIcon(LoadImage("..\\assets\\images\\icon\\icon.png"));
    #else
        _window->setIcon(LoadImage("assets/images/icon/icon.png"));
    #endif

    _camera = new Raylib::Core::CameraB(a, b, c, 45.0f, CAMERA_PERSPECTIVE);
    this->_menu = new Bomberman::Menu(this->_window, &this->_state, &this->_currGameState);
    this->_pauseTxt = new Raylib::Texts::Text("PAUSE SCREEN", this->_window->getWidth() - 55, 20, 60, BLUE);
    this->_pauseTxtHelp = new Raylib::Texts::Text("PRESS ENTER to RESUME", this->_window->getWidth() - 140, 220, 50, BLUE);
    this->_HUDPlayer1Txt = new Raylib::Texts::Text("Hello", 100, 900, 60, BLUE);
    this->_HUDPlayer2Txt = new Raylib::Texts::Text("Hello", 1500, 20, 60, PURPLE);
    this->_HUDAi1Txt = new Raylib::Texts::Text("Hello", 1500, 900, 60, GREEN);
    this->_HUDAi2Txt = new Raylib::Texts::Text("Hello", 1500, 20, 60, PURPLE);
    this->_HUDAi3Txt = new Raylib::Texts::Text("Hello", 100, 20, 60, YELLOW);
    this->_WinTxt = new Raylib::Texts::Text("YOU WIN !", this->_window->getWidth(), 20, 60, GREEN);
    this->_Win1Txt = new Raylib::Texts::Text("PLAYER 1 WIN !", this->_window->getWidth() - 80, 20, 60, GREEN);
    this->_Win2Txt = new Raylib::Texts::Text("PLAYER 2 WIN !", this->_window->getWidth() - 80, 20, 60, GREEN);
    this->_LooseTxt = new Raylib::Texts::Text("YOU LOOSE !", this->_window->getWidth() - 45, 20, 60, RED);
    this->_EndTxtHelp = new Raylib::Texts::Text("Click RETURN to EXIT", this->_window->getWidth() - 140, 220, 50, BLUE);
    this->_ReturnTexIdle = new Raylib::Texture::Tex(ReturnIdle.getImage());
    this->_ReturnTexHover = new Raylib::Texture::Tex(ReturnHover.getImage());
    this->_ReturnBtn = this->_ReturnTexIdle;

    #if _WIN32
        _soundBombExplode = new Raylib::Audio::SoundB("..\\assets\\sounds\\bomb_explode.wav");
        _soundBombPlace = new Raylib::Audio::SoundB("..\\assets\\sounds\\bomb_drop.wav");
        _soundBoxBreak = new Raylib::Audio::SoundB("..\\assets\\sounds\\box_break.wav");
        _soundFootsteps = new Raylib::Audio::SoundB("..\\assets\\sounds\\footsteps.wav");
        _soundPlayerDeath = new Raylib::Audio::SoundB("..\\assets\\sounds\\player_death.wav");
        _soundPowerUpTake = new Raylib::Audio::SoundB("..\\assets\\sounds\\power_up_take.wav");
    #else
        _soundBombExplode = new Raylib::Audio::SoundB("assets/sounds/bomb_explode.wav");
        _soundBombPlace = new Raylib::Audio::SoundB("assets/sounds/bomb_drop.wav");
        _soundBoxBreak = new Raylib::Audio::SoundB("assets/sounds/box_break.wav");
        _soundFootsteps = new Raylib::Audio::SoundB("assets/sounds/footsteps.wav");
        _soundPlayerDeath = new Raylib::Audio::SoundB("assets/sounds/player_death.wav");
        _soundPowerUpTake = new Raylib::Audio::SoundB("assets/sounds/power_up_take.wav");
    #endif

    _soundBombPlace->setVolume(0.05f);
    _soundBombExplode->setVolume(0.5f);
    _soundBoxBreak->setVolume(1.0f);
    _soundFootsteps->setVolume(0.05f);
    _soundPlayerDeath->setVolume(0.75f);
    _soundPowerUpTake->setVolume(0.75f);

    #if _WIN32
        _music = new Raylib::Audio::MusicB("..\\assets\\musics\\main_theme.wav");
    #else
        _music = new Raylib::Audio::MusicB("assets/musics/main_theme.wav");
    #endif
    _music->setVolume(0.1f);

    #if _WIN32
        _ground = new Raylib::Models::ModelB("..\\assets\\models\\ground\\ground", "..\\assets\\textures\\ground\\ground", d, e);
    #else
        _ground = new Raylib::Models::ModelB("assets/models/ground/ground", "assets/textures/ground/ground", d, e);
    #endif
}

void Bomberman::Game::handleInput(void)
{
    switch (this->_state)
    {
        case GAME_SOLO_STATE:
            if (_input.isKeyPressed(KEY_ENTER)) {
                this->_state = PAUSE_STATE;
                _menu->setHasMusicChange(false);
            }
            break;
        case GAME_MULT_STATE:
            if (_input.isKeyPressed(KEY_ENTER)) {
                this->_state = PAUSE_STATE;
                _menu->setHasMusicChange(false);
            }
            break;
        case PAUSE_STATE:
            if (_input.isKeyPressed(KEY_ENTER)) {
                this->_state = this->_currGameState;
                _menu->setHasMusicChange(false);
            }
            break;
        default:
            break;
    }
}

void Bomberman::Game::handleSoloInput() {
    Bomberman::Entities::Player *player1 = nullptr;

    for (auto &player : _entitiesGame.getPlayers())
        if (player->getId() == 0)
            player1 = player;

    if (player1 == nullptr)
        return;
    if (!player1->getHasMoved() && player1->getIsMoving())
        return;
    if (_input.isKeyDown(KEY_LEFT_CONTROL) && _input.isKeyDown(KEY_S)) {
        _save.save(_entitiesGame, _powerUps);
        return;
    }
    if (_input.isKeyPressed(KEY_W)) {
        player1->setIsMoving(true);
        player1->setHasMoved(false);
        Vector3 a = { player1->getPosition().x + 10.0f, player1->getPosition().y, player1->getPosition().z };
        player1->setTargetPos(a);
    }
    if (_input.isKeyPressed(KEY_S)) {
        player1->setIsMoving(true);
        player1->setHasMoved(false);
        Vector3 b = { player1->getPosition().x - 10.0f, player1->getPosition().y, player1->getPosition().z };
        player1->setTargetPos(b);
    }
    if (_input.isKeyPressed(KEY_A)) {
        player1->setIsMoving(true);
        player1->setHasMoved(false);
        Vector3 c = { player1->getPosition().x, player1->getPosition().y, player1->getPosition().z - 10.0f};
        player1->setTargetPos(c);
    }
    if (_input.isKeyPressed(KEY_D)) {
        player1->setIsMoving(true);
        player1->setHasMoved(false);
        Vector3 d = { player1->getPosition().x, player1->getPosition().y, player1->getPosition().z + 10.0f };
        player1->setTargetPos(d);
    }
    if (_input.isKeyPressed(KEY_SPACE))
        player1->placeBomb(_soundBombPlace);
}

void Bomberman::Game::handleMultInput() {
    this->handleSoloInput();

    Bomberman::Entities::Player *player2 = nullptr;

    for (auto &player : _entitiesGame.getPlayers())
        if (player->getId() == 2)
            player2 = player;

    if (player2 == nullptr)
        return;
    if (!player2->getHasMoved() && player2->getIsMoving())
        return;
    if (_input.isKeyPressed(KEY_UP)) {
        player2->setIsMoving(true);
        player2->setHasMoved(false);
        Vector3 a = { player2->getPosition().x + 10.0f, player2->getPosition().y, player2->getPosition().z };
        player2->setTargetPos(a);
    }
    if (_input.isKeyPressed(KEY_DOWN)) {
        player2->setIsMoving(true);
        player2->setHasMoved(false);
        Vector3 b = { player2->getPosition().x - 10.0f, player2->getPosition().y, player2->getPosition().z };
        player2->setTargetPos(b);
    }
    if (_input.isKeyPressed(KEY_LEFT)) {
        player2->setIsMoving(true);
        player2->setHasMoved(false);
        Vector3 c = { player2->getPosition().x, player2->getPosition().y, player2->getPosition().z - 10.0f};
        player2->setTargetPos(c);
    }
    if (_input.isKeyPressed(KEY_RIGHT)) {
        player2->setIsMoving(true);
        player2->setHasMoved(false);
        Vector3 d = { player2->getPosition().x, player2->getPosition().y, player2->getPosition().z + 10.0f };
        player2->setTargetPos(d);
    }
    if (_input.isKeyPressed(KEY_RIGHT_CONTROL))
        player2->placeBomb(_soundBombPlace);
}

void Bomberman::Game::updateSoloLoop(void)
{
    std::vector<Bomberman::Entities::Bomb *> bombs;
    for (auto &player : this->_entitiesGame.getPlayers()) {
        bombs = player->getBombs();
        this->_powerUps.checkPlayer(player, _soundPowerUpTake);
        for (std::size_t i = 0; i < bombs.size(); i++) {
            if (bombs[i] == nullptr)
                continue;
            if (!bombs[i]->getTimer()->timerDone()) {
                bombs[i]->scaleUp();
                bombs[i]->getTimer()->updateTimer();
            } else {
                bombs[i]->setExplode(true);
                this->breakBox(player);
                _soundBombExplode->play();
                player->removeBomb(i);
                return;
            }
        }
    }
}

void Bomberman::Game::createMapObjects(void)
{
    int id = 0;
    std::size_t i = MAP_HEIGHT - 1;

    for (const auto &line: _map.getMap()) {
        for (std::size_t j = 0; j < line.size(); j++) {
            if (line[j] == BOX_CHARACTER && !_save.isSaved()) {
                Vector3 a = { j * 10.0f + 5.0f, 0.0f, i * 10.0f + 5.0f };
                this->_entitiesGame.addBox(new Bomberman::Entities::Box(a, id));
                id++;
            }
            if (line[j] == WALL_CHARACTER) {
                Vector3 b = { j * 10.0f + 5.0f, 0.0f, i * 10.0f + 5.0f };
                this->_entitiesGame.addWall(new Bomberman::Entities::Wall(b));
            }
        }
        i -= 1;
    }
}

void Bomberman::Game::updatePlayers(void) {
    for (auto &player : _entitiesGame.getPlayers()) {
        if (player->getIsMoving())
            player->update(_entitiesGame.getPlayers(), _entitiesGame.getWalls(), _entitiesGame.getBoxes(), _soundFootsteps);
    }
}

void Bomberman::Game::soloGameLoop(void)
{
    if (!_soloSelected) {
        this->soloLoadModels();
        _soloSelected = true;
    }
    if (!_map.isGenerated()) {
        _map.eraseMap();
        _map.generateMap();
        this->createMapObjects();
    }
    this->detectDeath();
    this->soloAi();
    this->handleSoloInput();
    this->updatePlayers();
    this->updateSoloLoop();
    this->drawSoloGame();
}

void Bomberman::Game::multGameLoop(void)
{
    if (!_multSelected) {
        this->soloLoadModels();
        _multSelected = true;
    }
    if (!_map.isGenerated()) {
        _map.eraseMap();
        _map.generateMap();
        this->createMapObjects();
    }
    this->detectMultDeath();
    this->multAi();
    this->handleMultInput();
    this->updatePlayers();
    this->updateSoloLoop();
    this->drawMultGame();
}

void Bomberman::Game::drawSoloGame(void)
{
    int playerLife = 0;
    int cpu1Life = 0;
    int cpu2Life = 0;
    int cpu3Life = 0;
    _draw.beginMode3D(_camera->getCamera());
    this->draw();
    _drawM.grid(100, 10.0f);
    _draw.endMode3D();
    for (auto &player : _entitiesGame.getPlayers()) {
        if (player->getId() == 0)
            playerLife = player->getLife();
        if (player->getId() == 1)
            cpu1Life = player->getLife();
        if (player->getId() == 2)
            cpu2Life = player->getLife();
        if (player->getId() == 3)
            cpu3Life = player->getLife();
    }
    this->_HUDPlayer1Txt->TextDraw(TextFormat("Player 1: %d", playerLife));
    this->_HUDAi1Txt->TextDraw(TextFormat("CPU 1: %d", cpu1Life));
    this->_HUDAi2Txt->TextDraw(TextFormat("CPU 2: %d", cpu2Life));
    this->_HUDAi3Txt->TextDraw(TextFormat("CPU 3: %d", cpu3Life));
}

void Bomberman::Game::drawMultGame(void)
{
    int player1Life = 0;
    int player2Life = 0;
    int cpu1Life = 0;
    int cpu2Life = 0;
    _draw.beginMode3D(_camera->getCamera());
    this->draw();
    _drawM.grid(100, 10.0f);
    _draw.endMode3D();
    for (auto &player : _entitiesGame.getPlayers()) {
        if (player->getId() == 0)
            player1Life = player->getLife();
        if (player->getId() == 1)
            cpu1Life = player->getLife();
        if (player->getId() == 2)
            player2Life = player->getLife();
        if (player->getId() == 3)
            cpu2Life = player->getLife();
    }
    this->_HUDPlayer1Txt->TextDraw(TextFormat("Player 1: %d", player1Life));
    this->_HUDPlayer2Txt->TextDraw(TextFormat("Player 2: %d", player2Life));
    this->_HUDAi1Txt->TextDraw(TextFormat("CPU 1: %d", cpu1Life));
    this->_HUDAi3Txt->TextDraw(TextFormat("CPU 2: %d", cpu2Life));
}

void Bomberman::Game::drawPause(void)
{
    Raylib::Core::Input input;
    Vector2 mouse_position = input.getMousePosition();

    switch (this->_currGameState)
    {
        case GAME_SOLO_STATE:
            this->drawSoloGame();
            break;
        case GAME_MULT_STATE:
            this->drawMultGame();
            break;
        default:
            break;
    }
    this->handlePauseEndInput(mouse_position);
    this->_pauseTxt->TextDraw();
    this->_pauseTxtHelp->TextDraw();
    this->_ReturnBtn->draw(this->_window->getWidth() - 575, 700, WHITE);
}

void Bomberman::Game::handlePauseEndInput(Vector2 mouse_position)
{
    float XPos = this->_window->getWidth() - 575;
    Rectangle btnBounds = {XPos, 700, 575, 80};
    if (CheckCollisionPointRec(mouse_position, btnBounds)) {
        this->_ReturnBtn = this->_ReturnTexHover;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            this->_soloSelected = false;
            this->_multSelected = false;
            this->_entitiesGame.destroy();
            this->_state = MENU_STATE;
            delete _music;
            #if _WIN32
                _music = new Raylib::Audio::MusicB("..\\assets\\musics\\main_theme.wav");
            #else
                _music = new Raylib::Audio::MusicB("assets/musics/main_theme.wav");
            #endif
            _music->setVolume(0.1f);
            _music->play();
            _menu->setHasMusicChange(true);
        }
    } else
        this->_ReturnBtn = this->_ReturnTexIdle;
}

void Bomberman::Game::drawLooseEnd(void)
{
    Raylib::Core::Input input;
    Vector2 mouse_position = input.getMousePosition();

    switch (this->_currGameState)
    {
        case GAME_SOLO_STATE:
            this->drawSoloGame();
            break;
        case GAME_MULT_STATE:
            this->drawMultGame();
            break;
        default:
            break;
    }
    this->handlePauseEndInput(mouse_position);
    this->_LooseTxt->TextDraw();
    this->_EndTxtHelp->TextDraw();
    this->_ReturnBtn->draw(this->_window->getWidth() - 575, 700, WHITE);
}

void Bomberman::Game::drawWinEnd(void)
{
    Raylib::Core::Input input;
    Vector2 mouse_position = input.getMousePosition();

    switch (this->_currGameState)
    {
        case GAME_SOLO_STATE:
            this->drawSoloGame();
            break;
        case GAME_MULT_STATE:
            this->drawMultGame();
            break;
        default:
            break;
    }
    this->handlePauseEndInput(mouse_position);
    if (_multWinState == MULT_END_WIN1_STATE)
        this->_Win1Txt->TextDraw();
    else if(_multWinState == MULT_END_WIN2_STATE)
        this->_Win2Txt->TextDraw();
    else
        this->_WinTxt->TextDraw();
    this->_EndTxtHelp->TextDraw();
    this->_ReturnBtn->draw(this->_window->getWidth() - 575, 700, WHITE);
}

void Bomberman::Game::run() {
    _music->play();
    while (!_window->shouldClose()) {
        this->handleInput();
        _draw.begin();
        _draw.clearBackground(RAYWHITE);
        _music->update();
        switch (this->_state)
        {
            case MENU_STATE:
                _map.setGenerated(false);
                this->_menu->draw(this->_window, &this->_state);
                break;
            case GAME_SOLO_STATE:
                if (!_menu->getHasMusicChange()) {
                    delete _music;
                    #if _WIN32
                        _music = new Raylib::Audio::MusicB("..\\assets\\musics\\game_theme.wav");
                    #else
                        _music = new Raylib::Audio::MusicB("assets/musics/game_theme.wav");
                    #endif
                    _music->setVolume(0.1f);
                    _music->play();
                    _menu->setHasMusicChange(true);
                }
                this->soloGameLoop();
                break;
            case GAME_MULT_STATE:
                if (!_menu->getHasMusicChange()) {
                    delete _music;
                    #if _WIN32
                        _music = new Raylib::Audio::MusicB("..\\assets\\musics\\game_theme.wav");
                    #else
                        _music = new Raylib::Audio::MusicB("assets/musics/game_theme.wav");
                    #endif
                    _music->setVolume(0.1f);
                    _music->play();
                    _menu->setHasMusicChange(true);
                }
                this->multGameLoop();
                break;
            case PAUSE_STATE:
                if (!_menu->getHasMusicChange()) {
                    delete _music;
                    #if _WIN32
                        _music = new Raylib::Audio::MusicB("..\\assets\\musics\\starting_theme.wav");
                    #else
                        _music = new Raylib::Audio::MusicB("assets/musics/starting_theme.wav");
                    #endif
                    _music->setVolume(0.1f);
                    _music->play();
                    _menu->setHasMusicChange(true);
                }
                this->drawPause();
                break;
            case END_WIN_STATE:
                if (!_menu->getHasMusicChange()) {
                    delete _music;
                    #if _WIN32
                        _music = new Raylib::Audio::MusicB("..\\assets\\musics\\starting_theme.wav");
                    #else
                        _music = new Raylib::Audio::MusicB("assets/musics/starting_theme.wav");
                    #endif
                    _music->setVolume(0.1f);
                    _music->play();
                    _menu->setHasMusicChange(true);
                }
                this->drawWinEnd();
                break;
            case END_LOOSE_STATE:
                if (!_menu->getHasMusicChange()) {
                    delete _music;
                    #if _WIN32
                        _music = new Raylib::Audio::MusicB("..\\assets\\musics\\starting_theme.wav");
                    #else
                        _music = new Raylib::Audio::MusicB("assets/musics/starting_theme.wav");
                    #endif
                    _music->setVolume(0.1f);
                    _music->play();
                    _menu->setHasMusicChange(true);
                }
                this->drawLooseEnd();
                break;
            default:
                break;
        }
        _draw.end();
    }
}

void Bomberman::Game::draw() {
    Vector3 a = { 0.0f, 0.0f, 0.0f };
    Vector3 b = { 0.0f, 0.0f, 0.0f };
    Vector3 c = { 0.0f, 0.0f, 0.0f };
    Vector3 d = { 0.0f, 0.0f, 0.0f };

    this->_ground->drawEx(a, 0.0f);
    for (auto &player : _entitiesGame.getPlayers()) {
        player->getModel()->drawEx(player->getRotationAxis(), player->getRotation());
        for (auto &bomb: player->getBombs())
            bomb->getModel()->drawEx(b, 0.0f);
    }
    for (auto &wall : _entitiesGame.getWalls())
        wall->getModel()->drawEx(c, 0.0f);
    for (auto &box : _entitiesGame.getBoxes())
        box->getModel()->drawEx(d, 0.0f);
    this->_powerUps.draw();
}

Bomberman::Entity::Entity(Raylib::Models::ModelB *model, int id)
{
    this->_id = id;
    this->_model = model;
}

Raylib::Models::ModelB *Bomberman::Entity::getModel(void) {
    return (this->_model);
}

int Bomberman::Entity::getId(void) {
    return (this->_id);
}

int Bomberman::Game::getBoxIndex(int id)
{
    int pos = 0;

    for (auto &currBox: _entitiesGame.getBoxes()) {
        if (currBox->getId() == id)
            return (pos);
        pos++;
    }
    return (-1);
}

int Bomberman::Game::getPlayerIndex(int id)
{
    int pos = 0;

    for (auto &currBox: _entitiesGame.getPlayers()) {
        if (currBox->getId() == id)
            return (pos);
        pos++;
    }
    return (-1);
}

void Bomberman::Game::soloAi() {
    for (auto &player : _entitiesGame.getPlayers()) {
        if (player->getId() == 0 || (!player->getHasMoved() && player->getIsMoving()))
            continue;

        if (!player->getTimer()->timerDone()) {
            player->getTimer()->updateTimer();
        } else {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, 4);
            int random = dis(gen);

            if (random == 0) {
                player->setIsMoving(true);
                player->setHasMoved(false);
                Vector3 a = { player->getPosition().x + 10.0f, player->getPosition().y, player->getPosition().z };
                player->setTargetPos(a);
            } else if (random == 1) {
                player->setIsMoving(true);
                player->setHasMoved(false);
                Vector3 b = { player->getPosition().x - 10.0f, player->getPosition().y, player->getPosition().z };
                player->setTargetPos(b);
            } else if (random == 2) {
                player->setIsMoving(true);
                player->setHasMoved(false);
                Vector3 c = { player->getPosition().x, player->getPosition().y, player->getPosition().z - 10.0f};
                player->setTargetPos(c);
            } else if (random == 3) {
                player->setIsMoving(true);
                player->setHasMoved(false);
                Vector3 d = { player->getPosition().x, player->getPosition().y, player->getPosition().z + 10.0f };
                player->setTargetPos(d);
            } else if (random == 4) {
                player->placeBomb(_soundBombPlace);
                std::random_device rd2;
                std::mt19937 gen2(rd2());
                std::uniform_int_distribution<> dis2(0, 3);
                int random2 = dis2(gen2);

                if (random2 == 0) {
                    player->setIsMoving(true);
                    player->setHasMoved(false);
                    Vector3 e = { player->getPosition().x + 10.0f, player->getPosition().y, player->getPosition().z};
                    Vector3 f = { player->getPosition().x, player->getPosition().y, player->getPosition().z - 10.0f };
                    player->setTargetPos(e);
                    player->setTargetPos(f);
                } else if (random2 == 1) {
                    player->setIsMoving(true);
                    player->setHasMoved(false);
                    Vector3 g = { player->getPosition().x - 10.0f, player->getPosition().y, player->getPosition().z };
                    Vector3 h = { player->getPosition().x, player->getPosition().y, player->getPosition().z + 10.0f };
                    player->setTargetPos(g);
                    player->setTargetPos(h);

                } else if (random2 == 2) {
                    player->setIsMoving(true);
                    player->setHasMoved(false);
                    Vector3 i = { player->getPosition().x + 10.0f, player->getPosition().y, player->getPosition().z - 10.0f};
                    Vector3 j = { player->getPosition().x - 10.0f, player->getPosition().y, player->getPosition().z};
                    player->setTargetPos(i);
                    player->setTargetPos(j);
                } else if (random2 == 3) {
                    player->setIsMoving(true);
                    player->setHasMoved(false);
                    Vector3 k = { player->getPosition().x, player->getPosition().y, player->getPosition().z + 10.0f};
                    Vector3 l = { player->getPosition().x + 10.0f, player->getPosition().y, player->getPosition().z};
                    player->setTargetPos(k);
                    player->setTargetPos(l);
                }
            }
            player->resetTimer();
        }
    }
}

void Bomberman::Game::multAi() {
    for (auto &player : _entitiesGame.getPlayers()) {
        if ((player->getId() == 0 || (!player->getHasMoved() && player->getIsMoving())) || (player->getId() == 2 || (!player->getHasMoved() && player->getIsMoving())))
            continue;

        if (!player->getTimer()->timerDone()) {
            player->getTimer()->updateTimer();
        } else {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, 4);
            int random = dis(gen);

            if (random == 0) {
                player->setIsMoving(true);
                player->setHasMoved(false);
                Vector3 a = { player->getPosition().x + 10.0f, player->getPosition().y, player->getPosition().z };
                player->setTargetPos(a);
            } else if (random == 1) {
                player->setIsMoving(true);
                player->setHasMoved(false);
                Vector3 b = { player->getPosition().x - 10.0f, player->getPosition().y, player->getPosition().z };
                player->setTargetPos(b);
            } else if (random == 2) {
                player->setIsMoving(true);
                player->setHasMoved(false);
                Vector3 c = { player->getPosition().x, player->getPosition().y, player->getPosition().z - 10.0f };
                player->setTargetPos(c);
            } else if (random == 3) {
                player->setIsMoving(true);
                player->setHasMoved(false);
                Vector3 d = { player->getPosition().x, player->getPosition().y, player->getPosition().z + 10.0f };
                player->setTargetPos(d);
            } else if (random == 4) {
                player->placeBomb(_soundBombPlace);
                std::random_device rd2;
                std::mt19937 gen2(rd2());
                std::uniform_int_distribution<> dis2(0, 3);
                int random2 = dis2(gen2);

                if (random2 == 0) {
                    player->setIsMoving(true);
                    player->setHasMoved(false);
                    Vector3 e = { player->getPosition().x + 10.0f, player->getPosition().y, player->getPosition().z};
                    Vector3 f = { player->getPosition().x, player->getPosition().y, player->getPosition().z - 10.0f};
                    player->setTargetPos(e);
                    player->setTargetPos(f);
                } else if (random2 == 1) {
                    player->setIsMoving(true);
                    player->setHasMoved(false);
                    Vector3 g = { player->getPosition().x - 10.0f, player->getPosition().y, player->getPosition().z };
                    Vector3 h = { player->getPosition().x, player->getPosition().y, player->getPosition().z + 10.0f };
                    player->setTargetPos(g);
                    player->setTargetPos(h);

                } else if (random2 == 2) {
                    player->setIsMoving(true);
                    player->setHasMoved(false);
                    Vector3 i = { player->getPosition().x, player->getPosition().y, player->getPosition().z -10.0f };
                    Vector3 j = { player->getPosition().x - 10.0f, player->getPosition().y, player->getPosition().z };
                    player->setTargetPos(i);
                    player->setTargetPos(j);
                } else if (random2 == 3) {
                    player->setIsMoving(true);
                    player->setHasMoved(false);
                    Vector3 k = { player->getPosition().x, player->getPosition().y, player->getPosition().z + 10.0f };
                    Vector3 l = { player->getPosition().x + 10.0f, player->getPosition().y, player->getPosition().z };
                    player->setTargetPos(k);
                    player->setTargetPos(l);
                }
            }
            player->resetTimer();
        }
    }
}

void Bomberman::Game::soloLoadModels() {
#if _WIN32
    Vector3 a = { 15.0f, 0.0f, 15.0f };
    Vector3 b = { 0.0f, 1.0f, 0.0f };
    Vector3 c = { 15.0f, 0.0f, 15.0f };
    Vector3 d = { 0.0f, 1.0f, 0.0f };
    Vector3 e = { 15.0f, 0.0f, 135.0f };
    Vector3 f = { 0.0f, 1.0f, 0.0f };
    Vector3 g = { 115.0f, 0.0f, 135.0f };
    Vector3 h = { 0.0f, 1.0f, 0.0f };
    Vector3 i = { 115.0f, 0.0f, 15.0f };
    Vector3 j = { 0.0f, 1.0f, 0.0f };

    if (_save.isSaved()) {
        _entitiesGame.addPlayer(new Bomberman::Entities::Player(0, "..\\assets\\textures\\character\\blue1", a, 0.0f, b));
        _save.load(&_entitiesGame, &_powerUps);
    }
    else {
        _entitiesGame.addPlayer(new Bomberman::Entities::Player(0, "..\\assets\\textures\\character\\blue1", c, 0.0f, d));
        _entitiesGame.addPlayer(new Bomberman::Entities::Player(1, "..\\assets\\textures\\character\\green1", e, 90.0f, f));
        _entitiesGame.addPlayer(new Bomberman::Entities::Player(2, "..\\assets\\textures\\character\\purple1", g, 180.0f, h));
        _entitiesGame.addPlayer(new Bomberman::Entities::Player(3, "..\\assets\\textures\\character\\yellow1", i, 270.0f, j));
    }
#else
    if (_save.isSaved()) {
        _entitiesGame.addPlayer(new Bomberman::Entities::Player(0, "assets/textures/character/blue1", (Vector3) {15.0f, 0.0f, 15.0f}, 0.0f, (Vector3) {0.0f, 1.0f, 0.0f}));
        _save.load(&_entitiesGame, &_powerUps);
    } else {
        _entitiesGame.addPlayer(new Bomberman::Entities::Player(0, "assets/textures/character/blue1", (Vector3) {15.0f, 0.0f, 15.0f}, 0.0f, (Vector3){0.0f, 1.0f, 0.0f}));
        _entitiesGame.addPlayer(new Bomberman::Entities::Player(1, "assets/textures/character/green1", (Vector3) {15.0f, 0.0f, 135.0f}, 90.0f, (Vector3){0.0f, 1.0f, 0.0f}));
        _entitiesGame.addPlayer(new Bomberman::Entities::Player(2, "assets/textures/character/purple1", (Vector3) {115.0f, 0.0f, 135.0f}, 180.0f, (Vector3){0.0f, 1.0f, 0.0f}));
        _entitiesGame.addPlayer(new Bomberman::Entities::Player(3, "assets/textures/character/yellow1", (Vector3) {115.0f, 0.0f, 15.0f}, 270.0f, (Vector3){0.0f, 1.0f, 0.0f}));
    }
#endif
    for (auto &player : _entitiesGame.getPlayers()) {
        std::cout << player->getId() << std::endl;
    }
}
