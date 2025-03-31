/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD09-lucas.casado
** File description:
** Paladin
*/

#include "Paladin.hpp"

Paladin::Paladin(std::string name, int power) : Peasant(name, power), Knight(name, power), Priest(name, power)
{
    this->_name = name;
    this->_health = 100;
    
    if (power > 100)
        this->_power = 100;
    else
        this->_power = power;

    std::cout << this->_name << " fights for the light." << std::endl;
}

int Paladin::attack()
{
    return(Knight::attack());
}

int Paladin::special()
{
    return(Priest::special());
}

void Paladin::rest()
{
    return(Priest::rest());
}

Paladin::~Paladin()
{
    std::cout << this->_name << " is blessed." << std::endl;
}