/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD07am-lucas.casado
** File description:
** Federation
*/

#include "Federation.hpp"
#include "WarpSystem.hpp"
#include "Borg.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    const auto sf = "The ship USS ";
    const auto ef = " has been finished.";
    const auto ss = "It is ";
    const auto ms = " m in length and ";
    const auto es = " m in width.";
    const auto st = "It can go to Warp ";

    this->_name = name;
    this->_width = width;
    this->_maxWarp = maxWarp;
    this->_length = length;

    std::cout << sf << this->_name << ef << std::endl;
    std::cout << ss << this->_length << 
        ms << this->_width << es << std::endl;
    std::cout << st << this->_maxWarp << "!" << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
    std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{

    const auto st = ": The core is stable at the time.";
    const auto unst = ": The core is unstable at the time.";

    if(!this->_core)
        return;
    if(this->_core->checkReactor()->isStable())
        std::cout << "USS " << this->_name << st <<std::endl;
    else
        std::cout << "USS " << this->_name << unst <<std::endl;
}

void Federation::Ship::checkCore()
{

    const auto st = ": The core is stable at the time.";
    const auto unst = ": The core is unstable at the time.";

    if(!this->_core)
        return;
    if(this->_core->checkReactor()->isStable())
        std::cout << this->_name << st <<std::endl;
    else
        std::cout << this->_name << unst <<std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
    const auto sf = "The independent ship ";
    const auto ef = " just finished its construction.";
    const auto ss = "It is ";
    const auto ms = " m in length and ";
    const auto es = " m in width.";

    this->_name = name;
    this->_width = width;
    this->_maxWarp = 1;
    this->_length = length;

    std::cout << sf << this->_name << ef << std::endl;
    std::cout << ss << this->_length << 
        ms << this->_width << es << std::endl;
}

void Federation::Starfleet::Ship:: promote(Federation::Starfleet::Captain * captain)
{
    const auto declaration = ": I'm glad to be the captain of the USS ";
    this->_captain = captain;

    std::cout << this->_captain->getName() << declaration << this->_name << "." << std::endl;
}

Federation::Starfleet::Captain::Captain(std::string name)
{
    this->_name = name;
    this->_age = getAge();
}

Federation::Starfleet::Captain::~Captain()
{   
}

std::string Federation::Starfleet::Captain::getName()
{
    return(this->_name);
}


int Federation::Starfleet::Captain::getAge()
{
    return(this->_age);
}

void Federation::Starfleet::Captain::setAge(int age)
{
    this->_age = age;
}


Federation::Starfleet::Ensign::Ensign(std::string name)
{
    const auto ensign = "Ensign ";
    const auto orders = ", awaiting orders.";

    this->_name = name;
    std::cout << ensign << name << orders << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}