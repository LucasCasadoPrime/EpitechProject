/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGRUSH3-lucas.casado
** File description:
** ModuleNetwork
*/

#ifndef MODULENETWORK_HPP_
#define MODULENETWORK_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <ncurses.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>
#include <sstream>
#include <ctime>

class ModuleNetwork {
    private:
        long long _download;
        long long _upload;

    public:
        ModuleNetwork();
        ~ModuleNetwork();

        void setData();
        const long long sendUpload() const;
        const long long sendDownload() const;

    protected:
};

#endif /* !MODULENETWORK_HPP_ */
