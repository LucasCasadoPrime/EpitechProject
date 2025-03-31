/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-clement.ozor
** File description:
** map
*/

#include "Map.hpp"

void Bomberman::Map::generateMap(void)
{
    #if _WIN32
        std::ifstream in("..\\datas\\default.map");
    #else
        std::ifstream in("datas/default.map");
    #endif
    std::vector<std::string> all_lines;
    std::string str;
    int random;

    srand(time(NULL));
    while (std::getline(in, str))
        if (str.size() > 0)
            all_lines.push_back(str);
    for (std::string &line: all_lines) {
        for (int i = 0; i < line.length(); i++) {
            if (line[i] != '0') continue;
            random = rand() % 3;
            if (random > 1) continue;
            line[i] = '7';
        }
        this->_map.push_back(line);
    }
    this->generated = true;
}

bool Bomberman::Map::isGenerated(void) {
    return this->generated;
}

void Bomberman::Map::setGenerated(bool value) {
    this->generated = value;
}

std::vector<std::string> Bomberman::Map::getMap(void) {
    return this->_map;
}

void Bomberman::Map::eraseMap(void) {
    this->_map.clear();
}