/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD10pm-lucas.casado
** File description:
** Oxygenator
*/

#ifndef OXYGENATOR_HPP_
#define OXYGENATOR_HPP_

#include "BaseComponent.hpp"

class Oxygenator : public BaseComponent
{
    public:
        Oxygenator();
        virtual ~Oxygenator() {}

        void generateOxygen();
        void useOxygen(int quantity);

    private:
        int _quantity;
};

#endif /* !OXYGENATOR_HPP_ */
