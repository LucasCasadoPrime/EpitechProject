/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGRUSH3-lucas.casado
** File description:
** ModuleDate
*/

#include "ModuleDate.hpp"

ModuleDate::ModuleDate() {
    this->setDate();
}

ModuleDate::~ModuleDate()
{
}

void ModuleDate::setDate() {
    this->_date.clear();
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    auto d = std::to_string(local_time->tm_mday);
    auto m = std::to_string(1 + local_time->tm_mon);
    auto y = std::to_string(1900 + local_time->tm_year);
    auto h = std::to_string(local_time->tm_hour);
    auto min = std::to_string(local_time->tm_min);
    auto sec = std::to_string(local_time->tm_sec);
    this->_date = d + "/" + m + '/' + y + ' ' + h + ':' + min + ':' + sec;
}

std::string ModuleDate::sendDate() const {
    return (this->_date);
}