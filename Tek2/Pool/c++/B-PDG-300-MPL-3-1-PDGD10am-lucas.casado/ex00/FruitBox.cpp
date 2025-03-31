/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD10am-lucas.casado
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size)
{
    this->_size = size;
    this->_header = NULL;
    this->_count = 0;
}

int FruitBox::nbFruits() const
{
    return(this->_count);
}

FruitNode *FruitBox::head() const
{
    return(this->_header);
}

FruitBox::~FruitBox()
{
}
