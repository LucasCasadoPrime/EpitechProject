/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD11-lucas.casado
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture() : _data("")
{
}

Picture::Picture(const std::string & filename)
{
    getPictureFromFile(filename);
}

bool Picture::getPictureFromFile(const std::string & name)
{
    const std::string error = "ERROR";
    std::ifstream stream(name.data());

    if(!stream.is_open()){
        this->_data = error;
        return (false);
    }
    std::stringstream rfile;
    rfile << stream.rdbuf();
    this->_data = rfile.str();
    return (true);
}

Picture::~Picture()
{

}