/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** Error
*/

#include "../include/Error.hpp"

plazza::Error::Error(std::string param)
{
    this->_msg = param;
}

plazza::Error::~Error(void) {}

const char *plazza::Error::what(void)
{
    return (this->_msg.c_str());
}