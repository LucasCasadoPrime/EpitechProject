/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** exception
*/

#include "error.hpp"

namespace arcade {
    Exception::Exception(const std::string &what) : _what(what)
    {
    }

    const char *Exception::what() const throw()
    {
        return (_what.c_str());
    }
}