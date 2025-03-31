/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD10am-lucas.casado
** File description:
** FruitNode
*/

#ifndef FRUITNODE_HPP_
#define FRUITNODE_HPP_

#include "Fruit.hpp"

class FruitNode {
    public:
        Fruit *content;
        Fruit *next;
};

#endif /* !FRUITNODE_HPP_ */
