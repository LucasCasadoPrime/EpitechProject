/*
** EPITECH PROJECT, 2022
** ModuleRam
** File description:
** ModuleRam
*/

#include "ModuleRam.hpp"
#include <fstream>
#include <algorithm>
#include <iomanip>

ModuleRam::ModuleRam() {

    this->setData();
}

ModuleRam::~ModuleRam() {

}

void ModuleRam::setData() {
    this->_ramAvailable.clear();
    this->_ramTotal.clear();
    this->_ramUsed.clear();
    this->_swapAvailable.clear();
    this->_swapTotal.clear();
    this->_swapUsed.clear();
    this->getRamInfo();
    this->getSwapInfo();
}

void ModuleRam::getRamInfo() {

    std::ifstream RamInfo("/proc/meminfo");
    std::string memTotal, memAvailable;

    std::getline(RamInfo, memTotal);
    for (int i = 0 ; i < 2 ; i++) {
        std::getline(RamInfo, memAvailable);
    }

    std::remove_if(memTotal.begin(), memTotal.end(), isspace);
    std::remove_if(memAvailable.begin(), memAvailable.end(), isspace);

    memTotal = memTotal.substr(memTotal.find(":") + 1);
    memAvailable = memAvailable.substr(memAvailable.find(":") + 1);
    memAvailable = memAvailable.substr(0, memAvailable.find("k"));
    memTotal = memTotal.substr(0, memTotal.find("k"));

    std::ostringstream stock;

    stock << std::setprecision(3) << std::stod(memTotal) / 1048576;
    _ramTotal = std::string(stock.str() + "Gb");
    stock.str("");
    stock << std::setprecision(3) << (std::stod(memAvailable) / 1048576);
    _ramAvailable = std::string(stock.str() + "Gb");
    stock.str("");
    stock << std::setprecision(2) << (std::stod(memTotal) - std::stod(memAvailable)) / 1048576;
    _ramUsed = std::string(stock.str() + "Gb");
    stock.str("");
    RamInfo.close();
}

void ModuleRam::getSwapInfo() {

    std::ifstream SwapInfo("/proc/meminfo");
    std::string swapTotal, swapAvailable;
    
    for (int i = 0 ; i < 14 ; i++) {
        std::getline(SwapInfo, swapTotal);
    }
    std::getline(SwapInfo, swapTotal);
    std::getline(SwapInfo, swapAvailable);

    std::remove_if(swapTotal.begin(), swapTotal.end(), isspace);
    std::remove_if(swapAvailable.begin(), swapAvailable.end(), isspace);

    swapTotal = swapTotal.substr(swapTotal.find(":") + 1);
    swapAvailable = swapAvailable.substr(swapAvailable.find(":") + 1);
    swapAvailable = swapAvailable.substr(0, swapAvailable.find("k"));
    swapTotal = swapTotal.substr(0, swapTotal.find("k"));

    std::ostringstream stock;

    stock << std::setprecision(3) << std::stod(swapTotal) / 1048576;
    _swapTotal = std::string(stock.str() + "Gb");
    stock.str("");
    stock << std::setprecision(3) << std::stod(swapAvailable) / 1048576;
    _swapAvailable = std::string(stock.str() + "Gb");
    stock.str("");
    stock << std::setprecision(2) << (std::stod(swapTotal) - std::stod(swapAvailable)) / 1048576;
    _swapUsed = std::string(stock.str() + "Gb");
    stock.str("");
    SwapInfo.close();
}

const std::string & ModuleRam::SendRamAvailable() const {

    return _ramAvailable;
}

const std::string & ModuleRam::SendRamUsed() const {

    return _ramUsed;
}

const std::string & ModuleRam::SendswapAvailable() const {

    return _swapAvailable;
}

const std::string & ModuleRam::SendSwapUsed() const {

    return _swapUsed;
}

const std::string & ModuleRam::SendRamTotal() const {

    return _ramTotal;
}

const std::string & ModuleRam::SendSwapTotal() const {

    return _swapTotal;
}

ModuleRam::ModuleRam(const ModuleRam &stk) {
    
    _ramUsed = stk._ramUsed;
    _ramAvailable = stk._ramAvailable;
    _ramTotal = stk._ramTotal;

    _swapUsed = stk._swapUsed;
    _swapAvailable = stk._swapAvailable;
    _swapTotal = stk._swapTotal;
}