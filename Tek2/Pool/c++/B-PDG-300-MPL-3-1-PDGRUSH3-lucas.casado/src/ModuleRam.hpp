/*
** EPITECH PROJECT, 2022
** ModuleRal
** File description:
** ModuleRam
*/

#ifndef MODULERAM_HPP
#define MODULERAM_HPP

#include "string"
#include "IMonitorModule.hpp"

class ModuleRam : public IMonitorModule
{
    public:
        ModuleRam();
        ~ModuleRam();
        ModuleRam(const ModuleRam &);
        const std::string& SendRamUsed() const;
        const std::string& SendRamAvailable() const;
        const std::string& SendRamTotal() const;
        const std::string& SendSwapUsed() const;
        const std::string& SendswapAvailable() const;
        const std::string& SendSwapTotal() const;
        void setData();
    private:
        void getRamInfo();;
        void getSwapInfo();
        std::string _ramUsed;
        std::string _ramAvailable;
        std::string _ramTotal;
        std::string _swapUsed;
        std::string _swapAvailable;
        std::string _swapTotal;
};

#endif /* !MODULERAM_HPP */