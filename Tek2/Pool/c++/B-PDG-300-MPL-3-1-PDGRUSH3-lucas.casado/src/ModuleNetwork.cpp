/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGRUSH3-lucas.casado
** File description:
** ModuleNetwork
*/

#include "ModuleNetwork.hpp"

bool isNumber(const std::string &s) {
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0) 
            return false;
    }
    return true;
}

ModuleNetwork::ModuleNetwork() {
    this->setData();
} 

ModuleNetwork::~ModuleNetwork() {

}

const long long ModuleNetwork::sendDownload() const {
    return (this->_download);
}

const long long ModuleNetwork::sendUpload() const {
    return (this->_upload);
}

void ModuleNetwork::setData() {
    std::ifstream networkFile("/proc/net/dev");
    std::string line;
    std::string word = "";
    int i = 0;
    int j = 0;

    this->_download = 0;
    this->_upload = 0;
    while (std::getline(networkFile, line)) {
        if (i > 1) {
            std::stringstream ss(line);
            while (ss >> word) {
                this->_download += (isNumber(word) && j >= 9) ? std::stoll(word) : 0;
                this->_upload += (isNumber(word) && j < 9) ? std::stoll(word) : 0;
                j++;
            }
        }
        i++;
    }
    networkFile.close();
}