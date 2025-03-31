/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** Loader
*/

#include "Loader.hpp"

namespace arcade {

    Loader::Loader(std::string filename)
    {
        _filename = filename;
        _type = UNKNOWN;
        _handle = nullptr;
        _handle = dlopen(_filename.c_str(), RTLD_LAZY);
        if (_handle == nullptr) {
            std::cout << _filename << dlerror() << std::endl;
            exit (84);
        }
    }

    type Loader::getType() {
        if (dlsym(_handle, "getGame") != nullptr)
            return(_type = GAME);
        if (dlsym(_handle, "getGraphical") != nullptr)
            return(_type = GRAPHICAL);
        return(_type = UNKNOWN);
    }

    void Loader::setGameName(const std::string name) {
        this->_gamename = name;
    }

    Loader::~Loader() {
        dlclose(_handle);
    }
}
