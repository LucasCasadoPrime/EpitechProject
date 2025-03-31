/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD10am-lucas.casado
** File description:
** Fruit
*/

#include "Fruit.hpp"

Fruit::Fruit(std::string name, int vitamins)
{
    this->_name = name;
    this->_vitamins = vitamins;
}

int Fruit::getVitamins()
{
    return(this->_vitamins);
}

std::string Fruit::getName()
{
    return(this->_name);
}

Fruit::~Fruit()
{
}