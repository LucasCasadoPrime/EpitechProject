/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD09-lucas.casado
** File description:
** Knight
*/

#include "Knight.hpp"

Knight::Knight(std::string name, int power) : Peasant(name, power)
{
    this->_name = name;
    this->_health = 100;
    
    if (power > 100)
        this->_power = 100;
    else
        this->_power = power;

    std::cout << this->_name << " vows to protect the kingdom." << std::endl;
}

int Knight::attack()
{
    if (this->_health <= 0) {
        this->_health = 0;
        std::cout << this->_name << " is out of combat." << std::endl;
        return (0);
    }
    if (this->_power < 10) {
        std::cout << this->_name << " is out of power." << std::endl;
        return (0);
    }
    this->_damage = 0;
    this->_power -= 10;
    this->_damage = 25;
    std::cout << this->Peasant::getName() << " strikes with his sword." << std::endl;
    return(this->_damage);
}

int Knight::special()
{
    if (this->_health <= 0) {
        this->_health = 0;
        std::cout << this->_name << " is out of combat." << std::endl;
        return (0);
    }
    if (this->_power < 30) {
        std::cout << this->_name << " is out of power." << std::endl;
        return (0);
    }
    this->_damage = 0;
    this->_power -= 30;
    this->_damage = 50;
    std::cout << this->Peasant::getName() << " impales his enemy." << std::endl;
    return(this->_damage);
}

void Knight::rest()
{
    if (this->_health <= 0) {
        this->_health = 0;
        std::cout << this->_name << " is out of combat." << std::endl;
        return;
    }else {
        this->_power += 50;
        if (this->_power > 100)
            this->_power = 100;
        std::cout << this->Peasant::getName() << " eats." << std::endl;
    }
}

Knight::~Knight()
{
    std::cout << this->Peasant::getName() << " takes off his armor." << std::endl;

}