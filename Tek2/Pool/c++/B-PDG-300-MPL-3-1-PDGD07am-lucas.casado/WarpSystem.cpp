/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD07am-lucas.casado
** File description:
** Warpsystem
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor(void)
{
    this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}

bool WarpSystem::QuantumReactor::isStable()
{
    if (this->_stability == true)
        return(true);
    return(false);
}

void WarpSystem::QuantumReactor::setStability (bool stability) 
{
    this->_stability = stability;
}

WarpSystem::Core::Core(QuantumReactor *reactor)
{
    this->_coreReactor = reactor;
}

WarpSystem::Core::~Core()
{
}


WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return(this->_coreReactor);
}
