/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD06-lucas.casado
** File description:
** KoalaNurse
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include "SickKoala.hpp"
#include <iostream>
#include <string>

class KoalaNurse {
    public:
        KoalaNurse(int);
        ~KoalaNurse();
        void giveDrug(std::string, SickKoala *);
        void timeCheck();
        std::string readReport(std::string);
    private:
        int ID;
        bool isWorking;
};

#endif /* !KOALANURSE_HPP_ */
