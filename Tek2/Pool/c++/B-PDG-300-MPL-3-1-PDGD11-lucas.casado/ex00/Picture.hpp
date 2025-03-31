/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD11-lucas.casado
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class Picture {
    public:
        Picture();
        Picture(const std::string &);
        bool getPictureFromFile(const std::string &);
        ~Picture();
        std::string _data;
};

#endif /* !PICTURE_HPP_ */
