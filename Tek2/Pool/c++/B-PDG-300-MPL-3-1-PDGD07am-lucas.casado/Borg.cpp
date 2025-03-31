/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD07am-lucas.casado
** File description:
** Borg
*/

#include "Borg.hpp"
#include "WarpSystem.hpp"
#include "Federation.hpp"

Borg::Ship::Ship()
{
    const auto sl = "We are the Borgs. Lower your shields and surrender yourselves unconditionally.";
    const auto ml = "Your biological characteristics and technologies will be assimilated.";
    const auto el = "Resistance is futile.";
    this->_side = 300;
    this->_maxWarp = 9;
    std::cout << sl << std::endl;
    std::cout << ml << std::endl;
    std::cout << el << std::endl;
}

Borg::Ship::~Ship()
{
}

void Borg::Ship::checkCore()
{

    const auto st = "Everything is in order.";
    const auto unst = "Critical failure imminent.";

    if(!this->_core)
        return;
    if(this->_core->checkReactor()->isStable())
        std::cout << st <<std::endl;
    else
        std::cout << unst <<std::endl;
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
}
