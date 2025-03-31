/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** Commande
*/

#include "../include/Commande.hpp"

plazza::Commande::Commande(std::string commande) 
{
    std::string delemiter = ":";
    std::string token = "";
    int pos = 0;
    int index = 0;

    while ((pos = commande.find(delemiter)) != std::string::npos) {
        token = commande.substr(0, pos);
        if (index == 0)
            this->_num = std::stoi(token);
        if (index == 1)
            this->_type = std::stoi(token);
        if (index == 2)
            this->_size = std::stoi(token);
        commande.erase(0, pos + delemiter.length());
        index++;
    }
    this->_quantity = std::stoi(commande);
}

plazza::Commande::~Commande() {}