/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD09-lucas.casado
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Enchanter.hpp"

class Priest : public Enchanter {
    private:
        std::string _name;
        int _power;
        int _health;
    public:
        Priest(std::string, int);
        void rest();
        ~Priest();
};

#endif /* !PRIEST_HPP_ */
