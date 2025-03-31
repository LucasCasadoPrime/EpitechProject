/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** Core
*/

#include "Core.hpp"

// _graphic n°0 = ncurses
// _graphic n°1 = sfml
// _graphic n°2 = sdl2

namespace arcade
{
    Core::Core(char *av) {
        _default = av;
        _graphic = 0;
        _game = 0;
        _menu = -1;
        running = true;
    }

    void Core::loadLibraries() {
        std::vector<std::string> libs;
        std::string prefix = "./lib/";
        std::string suffix = ".so";
        DIR *folder = opendir(prefix.c_str());
        struct dirent *entry;

        if (!folder) {
            std::cout << "ma 'lib' directory. Rebuild using 'make re'" << std::endl;
            exit(84);
        }
        while ((entry = readdir(folder))) {
            if (((std::string)&entry->d_name[std::strlen(entry->d_name) - 3]).compare(suffix) == 0) {
                libs.push_back(prefix + entry->d_name);
            }
        }
        for (std::string libNames : libs) {
            std::shared_ptr<Loader> loaderPtr = std::make_shared<Loader>(libNames);
            Loader *loader = loaderPtr.get();
            _loaders.push_back(loaderPtr);
            switch (loader->getType()) {
            case GAME:
                _games.push_back(loader->getInterface<iGame *>());
                if (libNames.substr(6).find("arcade_menu.so") != std::string::npos)
                    _game = _menu = _games.size() - 1;
                std::cout << libNames.substr(6) << " = GAME" << std::endl;
                break;
            case GRAPHICAL:
                _graphics.push_back(loader->getInterface<iGraphical *>());
                if (_default.find(libNames.substr(6)) != std::string::npos) {
                    _graphic = _graphics.size() - 1;
                    found = true;
                }
                std::cout << libNames.substr(6) << " = GRAPHICAL" << std::endl;
                break;
            case UNKNOWN:
                std::cout << libNames.substr(6) << " = UNKNOWN" << std::endl;
                break;
            }
        }
        closedir(folder);
        return;
    }

    void Core::handleKeys(int key)
    {
        if (key == F1) {
            if (_graphic - 1 >= 0) {
                _graphics[_graphic]->close();
                _graphic -= 1;
                _graphics[_graphic]->init();
            }
        }
        if (key == F2) {
            if (_graphic + 2 <= (int)_graphics.size()) {
                _graphics[_graphic]->close();
                _graphic += 1;
                _graphics[_graphic]->init();
            }
        }
        if (key == F5) {
            if (_game - 1 >= 0)
                _game -= 1;
        }
        if (key == F6) {
            if (_game + 2 <= (int)_games.size())
                _game += 1;
        }
        if (key == ESCAPE) {
            if (_games[_game]->getName() != "Menu") {
                _game = 2;
                return;
            }
            else {
                running = false;
                return;
            }
        }
    }

    void Core::runtime()
    {
        int key = -1;
        try {
            _graphics[_graphic]->init();
            while (running == true) {
                key = _graphics[_graphic]->handleKeys();
                handleKeys(key);
                _graphics[_graphic]->display(_games[_game]->runtime(key, _game, running));
                _graphics[_graphic]->erase();
                key = -1;
            }
            _graphics[_graphic]->close();
        }
        catch (arcade::Exception &error) {
            throw error;
        }
    }
    Core::~Core() {}
}