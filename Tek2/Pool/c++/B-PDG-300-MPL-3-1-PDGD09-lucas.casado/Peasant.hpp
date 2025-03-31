/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD09-lucas.casado
** File description:
** Peasant
*/

#ifndef PEASANT_HPP_
#define PEASANT_HPP_

#include <string>
#include <iostream>

class Peasant {
    protected:
        std::string _name;
        int _power;
        int _health;
    public:
        int _damage;
        Peasant(std::string, int);
        const std::string &getName() const;
        int getPower() const;
        int getHp () const;
        int attack();
        int special();
        void rest();
        void damage(int);
        ~Peasant();
};

#endif /* !PEASANT_HPP_ */
