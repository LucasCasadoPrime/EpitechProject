/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD10am-lucas.casado
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <string>

class Fruit {
    private:
        std::string _name;
        int _vitamins;
    public:
        Fruit(std::string, int);
        int getVitamins();
        std::string getName();
        ~Fruit();
};

#endif /* !FRUIT_HPP_ */
