/*
** EPITECH PROJECT, 2022
** ModuleUser
** File description:
** ModuleUser
*/

#ifndef MODULEUSER_HPP
#define MODULEUSER_HPP

#include "string"
#include "IMonitorModule.hpp"

class ModuleUser : public IMonitorModule {
    public:
        ModuleUser();
        ~ModuleUser();
        const std::string &getUsername() const;
        const std::string &getHostname() const;
    protected:
    private:
        void setUsername();
        void setHostname();
        const std::string _name;
        std::string _username;
        std::string _hostname;
};

#endif /* !MODULEUSER_HPP */