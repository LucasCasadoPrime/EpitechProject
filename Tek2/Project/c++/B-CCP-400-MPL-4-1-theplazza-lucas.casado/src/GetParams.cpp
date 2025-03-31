/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** getParams
*/

#include "../include/GetParams.hpp"
#include "../include/Error.hpp"


plazza::GetParams::GetParams(int argc, char **argv)
{
    if (argc != 4)
        throw plazza::Error("Invalid input(s) at start");
    if (std::atoi(argv[1]) != 0)
        this->coefficient = std::atoi(argv[0]);
    if (std::atoi(argv[2]) != 0)
        this->nbCooks = std::atoi(argv[1]);
    if (std::atoi(argv[3]) != 0)
        this->timeRefill = std::atoi(argv[2]);
    else
        throw plazza::Error("Invalid input(s) at start");
}


plazza::GetParams::~GetParams() {}