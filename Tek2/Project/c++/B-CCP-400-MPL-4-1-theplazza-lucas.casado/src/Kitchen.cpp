/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** Kitchen
*/

#include "../include/Kitchen.hpp"

plazza::Kitchen::Kitchen(int nbr_of_cook, int kitchenID) 
{
    this->init();
    this->_threadpool.createThread(nbr_of_cook);
    this->_client.init();
    this->_kitchenId = kitchenID;
}

plazza::Kitchen::~Kitchen() 
{
    std::cout << "have been destroyed" << std::endl;
}

void plazza::Kitchen::init()
{
    this->_eggplant = 5;
    this->_goat_cheese = 5;
    this->_gruyere = 5;
    this->_ham = 5;
    this->_mushrooms = 5;
    this->_steak = 5;
    this->_tomato = 5;
}

void plazza::Kitchen::getData()
{
    int iterator = 0;

    for (; iterator < 5; iterator++) {
        std::string reponse = this->_client.sendData("tt");
        if (reponse != "none")
            break;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    if (iterator == 4) {
        std::cout << "start destroy" << std::endl;
        this->_threadpool.destroy();
    }
    this->~Kitchen();
    exit(0);
}