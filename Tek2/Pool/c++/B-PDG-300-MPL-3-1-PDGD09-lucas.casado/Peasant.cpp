/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD09-lucas.casado
** File description:
** Peasant
*/

#include "Peasant.hpp"

Peasant::Peasant(std::string name, int power)
{
    this->_name = name;
    this->_health = 100;
    
    if (power > 100)
        this->_power = 100;
    else
        this->_power = power;

    std::cout << this->_name << " goes for an adventure." << std::endl;
}

const std::string & Peasant::getName() const
{
    return(this->_name);
}

int Peasant::getPower() const
{
    return(this->_power);
}

int Peasant::getHp() const
{
    return(this->_health);
}

int Peasant::attack()
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
    this->_damage = 5;
    std::cout << this->getName() << " tosses a stone." << std::endl;
    return(this->_damage);
}

int Peasant::special()
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
    std::cout << this->getName() << " doesn't know any special move." << std::endl;
    return(this->_damage);
}

void Peasant::rest()
{

    if (this->_health <= 0) {
        this->_health = 0;
        std::cout << this->_name << " is out of combat." << std::endl;
        return;
    }
    if (this->_power <= 0) {
        std::cout << this->_name << " is out of power." << std::endl;
        return;
    }
    else {
        this->_power += 30;
        if (this->_power > 100)
            this->_power = 100;
        std::cout << this->getName() << " takes a nap." << std::endl;
    }
}

void Peasant::damage(int damage)
{
    if(damage >= 0) {
        this->_health -= damage;
        if(this->_health <= 0){
            this->_health = 0;
            std::cout << this->getName() << " is out of combat." << std::endl;
        }
        else 
            std::cout << this->getName() << " takes " << damage << " damage." << std::endl;
    }
}



Peasant::~Peasant()
{
    std::cout << this->getName() << " is back to his crops." << std::endl;
}