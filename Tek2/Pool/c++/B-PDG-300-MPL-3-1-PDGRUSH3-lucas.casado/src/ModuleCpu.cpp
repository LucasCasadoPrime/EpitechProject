/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGRUSH3-lucas.casado
** File description:
** ModuleCpu
*/

#include "ModuleCpu.hpp"

bool isNumber(const std::string &s);

ModuleCpu::ModuleCpu(): _cpuNumber(std::thread::hardware_concurrency()) {
    this->setCpu();
}

ModuleCpu::~ModuleCpu()
{
}

std::string giveLine(int nb, std::string text) {
    std::ifstream f(text);
    std::string s;

    for (int i = 0; i < nb; i++)
        std::getline(f, s);
    f.close();
    return (s);
}

std::vector<long long> splitToDouble(std::string str) {
    std::istringstream is(str);
    std::vector<long long> result;

    for (std::string s; is >> s;) {
        if (isNumber(s))
            result.push_back(std::stoll(s));
    }
    return (result);
}

void ModuleCpu::setCpu() {
    long int idle = 0;
    long int total = 0;
    float cputotal = 0;
    
    this->_cpuUsage.clear();
    this->_cpuRes.clear();
    for (int i = 0; i < this->_cpuNumber; i++) {
        this->_cpuUsage = (splitToDouble(giveLine(i+2, "/proc/stat")));
        total = (this->_cpuUsage[0]) + (this->_cpuUsage[1]) + (this->_cpuUsage[2]) + (this->_cpuUsage[3]) + (this->_cpuUsage[4]) + (this->_cpuUsage[5]) + (this->_cpuUsage[6]);
        idle = this->_cpuUsage[3];
        cputotal = static_cast<float>(idle * 100) / (total);
        cputotal = 100 - cputotal;
        this->_cpuRes.push_back(cputotal);
    }
}

float ModuleCpu::sendCpu(size_t cpuIndex) const {
    return (this->_cpuRes[cpuIndex]);
}

const size_t ModuleCpu::getCpuNbr() const {
    return (this->_cpuNumber);
}

const long long ModuleCpu::getTotal() const {
    double total = 0;
    for (size_t i = 0; i < this->_cpuNumber; i++) {
        total += this->_cpuUsage[i];
    }
    total /= this->_cpuNumber ;
    return (total);
}