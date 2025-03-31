/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD06-lucas.casado
** File description:
** KoalaDoctor
*/

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name)
{
    const auto doctor = "Dr.";
    const auto im = ": I ' m";
    const auto koerg = "! How do you kreog ?";
    this->name = name;

    std::cout << doctor << this->name <<
         im << this->name << koerg << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
    this->name = "";
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    std::vector<std::string> drugs = {"Mars", "Kinder", "Crunch", "Maroilles", "Eucalyptus leaf"};
    const auto doctor = "Dr.";
    const auto mid = ": So what's goerking you Mr.";
    std::string patientName = patient->getName();
    std::string filename = "";
    std::ofstream stream;
    int index = random() % 5;

    std::cout << doctor << this->name << mid << patientName << "?" << std::endl;
    patient->poke();
    filename = patientName;
    filename += ".report";
    stream.open(filename.c_str());
    if (!stream.is_open()){
        stream << drugs[index];
    }
}

void KoalaDoctor::timeCheck()
{
    const auto doctor = "Dr.";
    const auto go_work = ": Time to get to work!";
    const auto go_forest = ": Time to go home to my eucalyptus forest!";

    if (this->isWorking == false){
        std::cout << doctor << this->name << go_work << std::endl;
        this->isWorking = true;
    } else {
        std::cout << doctor << this->name << go_forest << std::endl;
        this->isWorking = false;
    }
}