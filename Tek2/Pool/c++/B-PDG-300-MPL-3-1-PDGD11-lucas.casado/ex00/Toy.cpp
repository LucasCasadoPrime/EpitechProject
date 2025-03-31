/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD11-lucas.casado
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy() : _type(BASIC_TOY), _name("toy")
{
}

Toy::Toy(ToyType type, std::string const & name, std::string const & str) : _type(type), _name(name), _picture(str)
{
}

Toy::Toy(Toy const & toy) : _type(toy._type), _name(toy._name), _picture(toy._picture)
{
}

void Toy::setName(std::string name)
{
    this->_name = name;
}

Toy::ToyType Toy::getType() const
{
    return(this->_type);
}

std::string Toy::getName() const
{
    return(this->_name);
}

std::string Toy::getAscii() const
{
    return(this->_picture._data);
}

bool Toy::setAscii(std::string str)
{
    if(this->_picture.getPictureFromFile(str) == true)
        return (true);
    return(false);
}

Toy::~Toy()
{
}
