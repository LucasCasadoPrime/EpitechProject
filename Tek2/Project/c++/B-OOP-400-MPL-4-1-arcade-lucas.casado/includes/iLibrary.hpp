/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** iLibrary
*/

#ifndef ILIBRARY_HPP_
#define ILIBRARY_HPP_

#include <string>
#include "entities.hpp"

namespace arcade
{
    class iLibrary
    {
        private:
        public:
            virtual ~iLibrary() = default;
            virtual void init() = 0;
            virtual std::string getName() = 0;
    };
} // namespace arcade


#endif /* !ILIBRARY_HPP_ */
