/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-clement.ozor
** File description:
** SaveAndLoad
*/

#include "SaveAndLoad.hpp"

Bomberman::SaveAndLoad::SaveAndLoad()
{
}

Bomberman::SaveAndLoad::~SaveAndLoad()
{
}

void Bomberman::SaveAndLoad::save(Entities::Entities entitiesGame, PowerUp::PowerUp powerUps) {
    std::fstream filePlayers;
    #if _WIN32
        filePlayers.open("..\\datas\\players.sav");
    #else
        filePlayers.open("datas/players.sav", std::ios::out);
    #endif

    for (auto &player : entitiesGame.getPlayers())
        filePlayers << player->getId() << " " << roundFloat(player->getTargetPosition().x) << " " << roundFloat(player->getTargetPosition().y) << " " << roundFloat(player->getTargetPosition().z) << std::endl;
    filePlayers.close();

    std::fstream fileBoxes;
    #if _WIN32
        fileBoxes.open("..\\datas\\boxes.sav", std::ios::out);
    #else
        fileBoxes.open("datas/boxes.sav", std::ios::out);
    #endif
    for (auto &box : entitiesGame.getBoxes())
        fileBoxes << box->getId() << " " << roundFloat(box->getPosition().x) << " " << roundFloat(box->getPosition().y) << " " << roundFloat(box->getPosition().z) << std::endl;
    fileBoxes.close();

    std::fstream filePowerUpBombs;
    #if _WIN32
        filePowerUpBombs.open("..\\datas\\powerups_bombs.sav", std::ios::out);
    #else
        filePowerUpBombs.open("datas/powerups_bombs.sav", std::ios::out);
    #endif
    for (auto &bomb : powerUps.getBomb())
        filePowerUpBombs <<roundFloat( bomb->getPosition().x) << " " <<roundFloat( bomb->getPosition().y) << " " <<roundFloat( bomb->getPosition().z) << std::endl;
    filePowerUpBombs.close();

    std::fstream filePowerUpWallPass;
    #if _WIN32
        filePowerUpWallPass.open("..\\datas\\powerups_wallpass.sav", std::ios::out);
    #else
        filePowerUpWallPass.open("datas/powerups_wallpass.sav", std::ios::out);
    #endif
    for (auto &wall : powerUps.getWallPass())
        filePowerUpWallPass <<roundFloat( wall->getPosition().x) << " " <<roundFloat( wall->getPosition().y) << " " <<roundFloat( wall->getPosition().z) << std::endl;
    filePowerUpWallPass.close();

    std::fstream filePowerUpSpeed;
    #if _WIN32
        filePowerUpSpeed.open("..\\datas\\powerups_speed.sav", std::ios::out);
    #else
        filePowerUpSpeed.open("datas/powerups_speed.sav", std::ios::out);
    #endif
    for (auto &speed : powerUps.getSpeed())
        filePowerUpSpeed << roundFloat(speed->getPosition().x) << " " << roundFloat(speed->getPosition().y) << " " << roundFloat(speed->getPosition().z) << std::endl;
    filePowerUpSpeed.close();

    std::fstream filePowerUpRange;
    #if _WIN32
        filePowerUpRange.open("..\\datas\\powerups_range.sav", std::ios::out);
    #else
        filePowerUpRange.open("datas/powerups_range.sav", std::ios::out);
    #endif
    for (auto &range : powerUps.getRange())
        filePowerUpRange << roundFloat(range->getPosition().x) << " " << roundFloat(range->getPosition().y) << " " << roundFloat(range->getPosition().z) << std::endl;
    filePowerUpRange.close();
}

void Bomberman::SaveAndLoad::load(Entities::Entities *entitiesGame, PowerUp::PowerUp *powerUps)
{
    int id;
    float x, y, z;

    std::fstream filePlayers;
    #if _WIN32
        filePlayers.open("..\\datas\\players.sav");
    #else
        filePlayers.open("datas/players.sav");
    #endif
    filePlayers >> id >> x >> y >> z;
    Vector3 Sal = {x,y,z};
    Vector3 didier2 = { 0.0f, 1.0f, 0.0f };
    while (!filePlayers.eof()) {
        if (id == 0)
            entitiesGame->getPlayers()[0]->setPosition(Sal);
        else {
            if (id == 1)
                #if _WIN32
                    entitiesGame->addPlayer(new Bomberman::Entities::Player(id, "..\\assets\\textures\\character\\green1", Sal, 0.0f, didier2));
                #else
                    entitiesGame->addPlayer(new Bomberman::Entities::Player(id, "assets/textures/character/green1", Sal, 0.0f, didier2));
                #endif
            if (id == 2)
                #if _WIN32
                    entitiesGame->addPlayer(new Bomberman::Entities::Player(1, "..\\assets\\textures\\character\\purple1", Sal, 90.0f, didier2));
                #else
                    entitiesGame->addPlayer(new Bomberman::Entities::Player(1, "assets/textures/character/purple1", Sal, 90.0f, didier2));
                #endif
            if (id == 3)
                #if _WIN32
                    entitiesGame->addPlayer(new Bomberman::Entities::Player(2, "..\\assets\\textures\\character\\yellow1", Sal, 180.0f, didier2));
                #else
                    entitiesGame->addPlayer(new Bomberman::Entities::Player(2, "assets/textures/character/yellow1", Sal, 180.0f, didier2));
                #endif
        }
        filePlayers >> id >> x >> y >> z;
        Sal = { x,y,z };
    }
    filePlayers.close();

    std::fstream fileBoxes;
    #if _WIN32
        fileBoxes.open("..\\datas\\boxes.sav");
    #else
        fileBoxes.open("datas/boxes.sav");
    #endif
    fileBoxes >> id >> x >> y >> z;
    Sal = { x,y,z };
    while (!fileBoxes.eof()) {
        entitiesGame->addBox(new Bomberman::Entities::Box(Sal, id));
        fileBoxes >> id >> x >> y >> z;
        Sal = { x,y,z };
    }
    fileBoxes.close();

    std::fstream filePowerUpBombs;
    #if _WIN32
        filePowerUpBombs.open("..\\datas\\powerups_bombs.sav");
    #else
        filePowerUpBombs.open("datas/powerups_bombs.sav");
    #endif
    filePowerUpBombs >> x >> y >> z;
    Sal = { x,y,z };
    while (!filePowerUpBombs.eof()) {
        powerUps->addBomb(Sal);
        filePowerUpBombs >> x >> y >> z;
        Sal = { x,y,z };
    }
    filePowerUpBombs.close();

    std::fstream filePowerUpWallpass;
    #if _WIN32
        filePowerUpWallpass.open("..\\datas\\powerups_wallpass.sav");
    #else
        filePowerUpWallpass.open("datas/powerups_wallpass.sav");
    #endif
    filePowerUpWallpass >> x >> y >> z;
    Sal = { x,y,z };
    while (!filePowerUpWallpass.eof()) {
        powerUps->addWallPass(Sal);
        filePowerUpWallpass >> x >> y >> z;
        Sal = { x,y,z };
    }
    filePowerUpWallpass.close();

    std::fstream filePowerUpSpeed;
    #if _WIN32
        filePowerUpSpeed.open("..\\datas\\powerups_speed.sav");
    #else
        filePowerUpSpeed.open("datas/powerups_speed.sav");
    #endif
    filePowerUpSpeed >> x >> y >> z;
    Sal = { x,y,z };
    while (!filePowerUpSpeed.eof()) {
        powerUps->addSpeed(Sal);
        filePowerUpSpeed >> x >> y >> z;
        Sal = { x,y,z };
    }
    filePowerUpSpeed.close();

    std::fstream filePowerUpRange;
    #if _WIN32
        filePowerUpRange.open("..\\datas\\powerups_range.sav");
    #else
        filePowerUpRange.open("datas/powerups_range.sav");
    #endif
    filePowerUpRange >> x >> y >> z;
    Sal = { x,y,z };
    while (!filePowerUpRange.eof()) {
        powerUps->addRange(Sal);
        filePowerUpRange >> x >> y >> z;
        Sal = { x,y,z };
    }
    filePowerUpRange.close();
}

bool Bomberman::SaveAndLoad::isSaved() {
    #if _WIN32
        std::ifstream f("..\\datas\\players.sav");
    #else
        std::ifstream f("datas/players.sav");
    #endif
    return f.good();
}

float Bomberman::SaveAndLoad::roundFloat(float value, int precision) {
    float pow_10 = pow(10.0f, (float) precision);
    return round(value * pow_10) / pow_10;
}