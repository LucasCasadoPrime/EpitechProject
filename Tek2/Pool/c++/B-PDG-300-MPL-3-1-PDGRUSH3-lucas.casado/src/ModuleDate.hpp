/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGRUSH3-lucas.casado
** File description:
** ModuleDate
*/

#ifndef MODULEDATE_HPP_
#define MODULEDATE_HPP_

#include "IMonitorModule.hpp"

class ModuleDate : public IMonitorModule {
    public:
        ModuleDate();
        ~ModuleDate();
        void setDate();
        std::string sendDate() const;
    protected:
        std::string _date;
};

#endif /* !MODULEDATE_HPP_ */
