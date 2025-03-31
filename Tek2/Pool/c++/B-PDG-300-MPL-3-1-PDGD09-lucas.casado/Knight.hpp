/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD09-lucas.casado
** File description:
** Knight
*/

#ifndef KNIGHT_HPP_
#define KNIGHT_HPP_

#include "Peasant.hpp"

class Knight : virtual public Peasant {
    private:
        std::string _name;
        int _power;
        int _health;
    public:
        int _damage;
        Knight(std::string, int);
        int attack();
        int special();
        void rest();
        ~Knight();
};

#endif /* !KNIGHT_HPP_ */
