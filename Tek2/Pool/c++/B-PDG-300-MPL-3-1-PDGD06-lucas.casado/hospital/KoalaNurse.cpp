/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD06-lucas.casado
** File description:
** KoalaNurse
*/

#include "KoalaNurse.hpp"
#include <fstream>


KoalaNurse::KoalaNurse(int ID)
{
    this->ID = ID;
    this->isWorking = false;
}

KoalaNurse::~KoalaNurse()
{
    const auto nurse = "Nurse";
    const auto rest = ": Finally some rest !";
    std::cout << nurse << this->ID << rest << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
    patient->takeDrug(drug);
}

void KoalaNurse::timeCheck()
{
    const auto nurse = "Nurse";
    const auto go_work = ": Time to get to work!";
    const auto go_forest = ": Time to go home to my eucalyptus forest!";

    if (this->isWorking == false){
        std::cout << nurse << this->ID << go_work << std::endl;
        this->isWorking = true;
    } else {
        std::cout << nurse << this->ID << go_forest << std::endl;
        this->isWorking = false;
    }
}

std::string KoalaNurse::readReport(std::string filename)
{   
    const auto nurse = "Nurse";
    const auto mister = ": Kreog ! Mr";
    const auto need = "needs a";
    const auto report = "report";
    std::string str;
    std::string drug = "";
    std::ifstream file;

    if (filename.substr(filename.find_last_of(".") + 1) == report) {
        str = filename.substr(0, filename.find("."));
        file.open(filename.c_str());
        if (file.is_open())
            std::getline(file, drug);
        if (drug != "")
            std::cout << nurse << this->ID << mister << str
                << need << drug << "!" << std::endl;
    }
}

