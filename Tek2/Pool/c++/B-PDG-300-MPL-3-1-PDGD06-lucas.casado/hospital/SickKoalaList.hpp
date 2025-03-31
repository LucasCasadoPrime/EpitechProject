/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD06-lucas.casado
** File description:
** SickKoalaList
*/

#ifndef SICKKOALALIST_HPP_
#define SICKKOALALIST_HPP_

#include "SickKoala.hpp"

class SickKoalaList {
    public:
        SickKoalaList(SickKoala *);
        ~SickKoalaList();
        SickKoalaList *getNext();
        SickKoala *content();
        std::string listName();
        bool isEnd();
        void setListNext(SickKoalaList *);
        void append(SickKoalaList *);
    private:
        std::string name;
        SickKoala *node;
        SickKoalaList *next;
};

#endif /* !SICKKOALALIST_HPP_ */
