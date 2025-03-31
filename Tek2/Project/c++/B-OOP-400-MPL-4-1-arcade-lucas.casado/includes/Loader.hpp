/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** Loader
*/

#ifndef LOADER_HPP_
#define LOADER_HPP_

#include <string>
#include <iostream>
#include <dlfcn.h>

namespace arcade
{
    enum type {
        GRAPHICAL,
        GAME,
        UNKNOWN,
    };

    class Loader {
        public:
            Loader(std::string filename);
            type getType();
            template <typename T> T getInterface() {
                T (*entrypoint)() = nullptr;
                if (_type == GRAPHICAL) {
                    *(void **)(&entrypoint) = dlsym(_handle, "getGraphical");
                    return (entrypoint());
                }
                if (_type == GAME) {
                    *(void **)(&entrypoint) = dlsym(_handle, "getGame");
                    return (entrypoint());
                }
                if (_type == UNKNOWN)
                    std::cout << _filename.c_str() << ": can't find entrypoint" << std::endl;
                return (nullptr);
            }
            void setGameName(const std::string);
            ~Loader();

        private:
            std::string _filename;
            std::string _gamename;
            void *_handle;
            type _type;
    };
} // namespace arcade


#endif /* !LOADER_HPP_ */
