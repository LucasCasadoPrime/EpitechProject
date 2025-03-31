/*
** EPITECH PROJECT, 2022
** ModuleOs
** File description:
** ModuleOs
*/

#include "ModuleOS.hpp"
#include <fstream>

ModuleOs::ModuleOs()
{
    this->setKernelVersion();
    this->setOSName();
}

ModuleOs::~ModuleOs()
{
}

void ModuleOs::setKernelVersion()
{
    std::ifstream KernelFile("/proc/sys/kernel/osrelease");

    if (!KernelFile.is_open()) {
        _kernelVersion = std::string("Version Unavailable");
        return;
    }
    std::getline(KernelFile, _kernelVersion);
    KernelFile.close();
}

void ModuleOs::setOSName()
{
    std::ifstream OSNameFile("/proc/sys/kernel/ostype");

    if (!OSNameFile.is_open()) {
        _osName = std::string("OS Name Unavailable");
        return;
    }
    std::getline(OSNameFile, _osName);
    OSNameFile.close();
}

const std::string & ModuleOs::sendKernelVersion() const
{
    return _kernelVersion;
}

const std::string & ModuleOs::sendOSName() const
{
    return _osName;
}