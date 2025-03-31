/*
** EPITECH PROJECT, 2022
** C++
** File description:
** sickkoala
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name)
{
    this->name = name;
}

SickKoala::~SickKoala()
{
    const auto mister = "Mr.";
    const auto goerk = ": Kreooogg!! I'm cuuuured!";
    std::cout << mister << this->name << goerk;
}

void SickKoala::poke()
{
    const auto mister = "Mr.";
    const auto goerk = ": Gooeeeeerrk!!";
    std::cout << mister << this->name << goerk << std::endl;
}

bool SickKoala::takeDrug(std::string str)
{
    const auto mister = "Mr.";
    const auto goerk = ": Gooeeeeerrk !!";
    const auto mars = "Mars";
    const auto kinder = "Kinder";

    if (std::strcmp(str.c_str(), mars) == 0){
        std::cout << mister << this->name << ": Mars, and it kreogs!" << std::endl;
        return(true);
    } else if (std::strcmp(str.c_str(), kinder) == 0) {
        std::cout << mister << this->name << ": Mars, and it kreogs!" << std::endl;
        return(true);
    } else {
        std::cout << mister << this->name << ": Kreooogg!! I'm cuuuured!" << std::endl;
        return(false);   
    }
}

void SickKoala::overDrive(std::string instance)
{
    const auto normal = "Kreog!";
    const auto fever = "1337!";
    const auto mister = "Mr.";
    while (instance.find(normal) != std::string::npos)
        instance.replace(instance.find(normal), strlen(normal), fever);
    std::cout << mister << this->name << ": " << instance << std::endl;
}

std::string SickKoala::getName()
{
    return(this->name);
}