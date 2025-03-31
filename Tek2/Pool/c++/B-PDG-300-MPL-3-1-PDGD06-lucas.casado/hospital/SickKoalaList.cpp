/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD06-lucas.casado
** File description:
** SickKoalaList
*/

#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *k)
{
    this->node = k;
    this->next = NULL;
    this->name = "NULL";
}

SickKoalaList::~SickKoalaList()
{
}

bool SickKoalaList::isEnd()
{
    if (this->next == NULL)
        return(true);
    return false;
}

void SickKoalaList::append(SickKoalaList * list)
{
    if (this->isEnd())
        this->setListNext(list);
    else
        this->next->append(list);
}

void SickKoalaList::setListNext(SickKoalaList *list)
{
    this->next = list;
}

SickKoalaList *SickKoalaList::getNext()
{
    return(this->next);
}

SickKoala *SickKoalaList::content()
{
    return(this->node);
}

std::string SickKoalaList::listName()
{
    return(this->name);
}