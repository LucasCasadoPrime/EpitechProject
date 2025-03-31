/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD09-lucas.casado
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Enchanter.hpp"
#include "Peasant.hpp"
#include "Knight.hpp"
#include "Priest.hpp"


class Paladin : public Knight, public Priest
{
    private:
        std::string _name;
        int _power;
        int _health;
    public:
        Paladin(std::string, int);
        int attack();
        int special();
        void rest();
        ~Paladin();
};

#endif /* !PALADIN_HPP_ */
