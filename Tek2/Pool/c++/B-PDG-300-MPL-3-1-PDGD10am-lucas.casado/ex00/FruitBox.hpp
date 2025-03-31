/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD10am-lucas.casado
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox {
    public:
        FruitBox(int);
        int FruitBox::nbFruits() const;
        FruitNode *FruitBox::head() const;
        bool FruitBox::putFruit(Fruit *fruit);
        Fruit *FruitBox::pickFruit();
        FruitNode *FruitBox::head() const;
        virtual ~FruitBox();
    protected:
        int _size;
        int _count;
        FruitNode *_header;
};

#endif /* !FRUITBOX_HPP_ */
