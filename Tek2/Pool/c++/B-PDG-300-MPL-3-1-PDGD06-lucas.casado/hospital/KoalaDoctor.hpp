/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD06-lucas.casado
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include "KoalaNurse.hpp"
#include "SickKoala.hpp"
#include <vector>
#include <string>
#include <fstream>

class KoalaDoctor {
    public:
        KoalaDoctor(std::string);
        ~KoalaDoctor();
        void diagnose(SickKoala *);
        void timeCheck();
    private:
        std::string name;
        bool isWorking;
};

#endif /* !KOALADOCTOR_HPP_ */
