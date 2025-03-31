/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD07am-lucas.casado
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_

#include "WarpSystem.hpp"

namespace Borg
{
    class Ship {
        private:
            int _side ;
            short _maxWarp ;
            WarpSystem::Core *_core;
        public:
            Ship();
            ~Ship();
            void checkCore();
            void setupCore(WarpSystem::Core *);
    };
}


#endif /* !BORG_HPP_ */
