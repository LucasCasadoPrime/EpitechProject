/*
** EPITECH PROJECT, 2022
** ModuleUser
** File description:
** ModuleUser
*/

#include "ModuleUser.hpp"
#include <iostream>
#include <unistd.h>

ModuleUser::ModuleUser() {
    this->setUsername();
    this->setHostname();
}

ModuleUser::~ModuleUser()
{
}

void ModuleUser::setUsername()
{
    _username = std::string(std::getenv("USER"));
}

void ModuleUser::setHostname()
{
    char name[1024] = "";
    gethostname(name, sizeof(name));
    _hostname = name;
}

std::string const & ModuleUser::getHostname() const
{
    return _hostname;
}

std::string const & ModuleUser::getUsername() const
{
    return _username;
}