/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** KitchenData
*/

#include "../include/KitchenData.hpp"

plazza::KitchenData::KitchenData(int id) 
{
    this->_id = id;
    this->_tomato = 5;
    this->_gruyere = 5;
    this->_ham = 5;
    this->_mushrooms = 5;
    this->_steak = 5;
    this->_eggplant = 5;
    this->_goat_cheese = 5;
}

plazza::KitchenData::~KitchenData() {}

void plazza::KitchenData::printInfo() 
{
    std::cout << "Cuisine numéro : " << this->_id << std::endl;
    std::cout << "Quantité d'ingrédient" << std::endl;
    std::cout << "tomate   \t:\t" << this->_tomato << std::endl;
    std::cout << "gruyere \t:\t" << this->_gruyere << std::endl;
    std::cout << "jambon   \t:\t" << this->_ham << std::endl;
    std::cout << "champignon \t:\t" << this->_mushrooms << std::endl;
    std::cout << "steak   \t:\t" << this->_steak << std::endl;
    std::cout << "aubergine \t:\t" << this->_eggplant << std::endl;
    std::cout << "fromage \t:\t" << this->_goat_cheese << std::endl;
}