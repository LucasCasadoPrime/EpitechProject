/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD09-lucas.casado
** File description:
** Enchenter
*/

#ifndef ENCHENTER_HPP_
#define ENCHENTER_HPP_

#include "Peasant.hpp"

class Enchanter : virtual public Peasant {
    private:
        std::string _name;
        int _power;
        int _health;
    public:
        int _damage;
        Enchanter(std::string, int);
        int attack();
        int special();
        void rest();
        ~Enchanter();
};

#endif /* !ENCHENTER_HPP_ */
