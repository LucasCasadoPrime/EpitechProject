/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD09-lucas.casado
** File description:
** Enchanter
*/

#include "Enchanter.hpp"

Enchanter::Enchanter(std::string name, int power) : Peasant(name, power)
{
    this->_name = name;
    this->_health = 100;
    
    if (power > 100)
        this->_power = 100;
    else
        this->_power = power;
    
    std::cout << this->_name << " learns magic from his spellbook." << std::endl;
}

int Enchanter::attack()
{
    if (this->_health <= 0) {
        this->_health = 0;
        std::cout << this->_name << " is out of combat." << std::endl;
        return (0);
    }
    if (this->_power <= 0) {
        std::cout << this->_name << " is out of power." << std::endl;
        return (0);
    }
    this->_damage = 0;
    this->_power -= 0;
    this->_damage = 0;
    std::cout << this->Peasant::getName() << " doesn’t know how to fight." << std::endl;
    return(this->_damage);
}

int Enchanter::special()
{
    if (this->_health <= 0) {
        this->_health = 0;
        std::cout << this->_name << " is out of combat." << std::endl;
        return (0);
    }
    if (this->_power < 50) {
        std::cout << this->_name << " is out of power." << std::endl;
        return (0);
    }
    this->_damage = 0;
    this->_power -= 50;
    this->_damage = 99;
    std::cout << this->Peasant::getName() << " casts a fireball." << std::endl;
    return(this->_damage);
}

void Enchanter::rest()
{
    if (this->_health <= 0) {
        this->_health = 0;
        std::cout << this->_name << " is out of combat." << std::endl;
        return;
    }else {
        this->_power += 100;
        if (this->_power > 100)
            this->_power = 100;
        std::cout << this->Peasant::getName() << " meditates." << std::endl;
    }
}

Enchanter::~Enchanter()
{
    std::cout << this->_name << " closes his spellbook." << std::endl;
}