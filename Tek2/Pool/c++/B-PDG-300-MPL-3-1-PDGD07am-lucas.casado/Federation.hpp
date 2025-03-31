/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD07am-lucas.casado
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <string>
#include <iostream>
#include "WarpSystem.hpp"

namespace Federation
{
    namespace Starfleet
    {

        class Captain {
            private:
                std::string _name;
                int _age;
            public:
                Captain(std::string);
                ~Captain();
                std::string getName();
                int getAge();
                void setAge(int age);
        };

        class Ensign {
            private:
                std::string _name;
            public:
                explicit Ensign(std::string);
                ~Ensign();

        };

        class Ship {
            private:
                int _length;
                int _width;
                std ::string _name ;
                short _maxWarp;
                WarpSystem::Core *_core;
                Federation::Starfleet::Captain * _captain;
            public:
                Ship(int,int,std::string ,short);
                void setupCore(WarpSystem::Core *);
                void checkCore();
                void promote(Federation::Starfleet::Captain *);
        };
    }
    class Ship {
        private:
            int _length;
            int _width;
            std ::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
        public:
            Ship(int length,int width,std::string name);
            void setupCore(WarpSystem::Core *);
            void checkCore();
    };
}

#endif /* !FEDERATION_HPP_ */

