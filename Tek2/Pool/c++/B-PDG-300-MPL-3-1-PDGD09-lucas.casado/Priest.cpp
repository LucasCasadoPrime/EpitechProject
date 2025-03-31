/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD09-lucas.casado
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest(std::string name, int power) : Peasant(name, power), Enchanter(name, power)
{
    this->_name = name;
    this->_health = 100;
    
    if (power > 100)
        this->_power = 100;
    else
        this->_power = power;
    
    std::cout << this->_name << " enters in the order." << std::endl;
}

void Priest::rest()
{
    if (this->_health <= 0) {
        this->_health = 0;
        std::cout << this->_name << " is out of combat." << std::endl;
        return;
    }
    if (this->_power <= 0) {
        std::cout << this->_name << " is out of power." << std::endl;
        return;
    } else {
        this->_power += 100;
        this->_health += 100;
        if (this->_power > 100)
            this->_power = 100;
        if (this->_health > 100)
            this->_health = 100;
        std::cout << this->Peasant::getName() << " prays." << std::endl;
    }
}

Priest::~Priest()
{
    std::cout << this->_name << " finds peace." << std::endl;
}