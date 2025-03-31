/*
** EPITECH PROJECT, 2022
** ModuleOs
** File description:
** ModuleOs
*/

#ifndef MODULEOS_HPP
#define MODULEOS_HPP

#include "string"
#include "IMonitorModule.hpp"

class ModuleOs : public IMonitorModule {
    public:
        ModuleOs();
        ~ModuleOs();
        void setKernelVersion();
        void setOSName();
        const std::string &sendKernelVersion() const;
        const std::string &sendOSName() const;
    protected:
    private:
        const std::string _name;
        std::string _kernelVersion;
        std::string _osName;
};

#endif /* !MODULEOS_HPP */