/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "iGraphical.hpp"
#include "iGame.hpp"

#include "Loader.hpp"

#include "Keys.hpp"
#include "entities.hpp"

#include "error.hpp"

#include <vector>
#include <string>
#include <dirent.h>
#include <stdexcept>
#include <iostream>
#include <cstring>
#include <memory>
#include <unistd.h>

#include <chrono>
#include <thread>

namespace arcade
{
    class Core {
        public:
            Core(char *av);
            ~Core();
            void runtime();
            void loadLibraries();
            void handleKeys(int key);
        private:
            std::vector<iGraphical *> _graphics;
            std::vector<iGame *> _games;
            std::vector<std::shared_ptr<Loader>> _loaders;
            std::string _default;
            bool found;
            int _graphic;
            int _game;
            int _menu;
            bool running;
    };
} // namespace arcade



#endif /* !CORE_HPP_ */
