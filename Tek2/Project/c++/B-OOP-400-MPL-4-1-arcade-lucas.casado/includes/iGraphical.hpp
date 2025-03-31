/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** iGraphical
*/

#ifndef IGRAPHICAL_HPP_
#define IGRAPHICAL_HPP_

#include "iLibrary.hpp"
#include "entities.hpp"
#include <vector>
#include <chrono>
#include <thread>
namespace arcade
{
    class iGraphical : public iLibrary {
        private:
        public:
            virtual ~iGraphical() = default;
            virtual void close() = 0;
            virtual void display(std::vector<std::pair<entitiesType, entities *>> ent) = 0;
            virtual void displaySprite(sprite *sprite) = 0;
            virtual int handleKeys() = 0;
            virtual void displayBox() = 0;
            virtual void erase() = 0;
            virtual void displayText(text *text) = 0;
    };
}

#endif /* !IGRAPHICAL_HPP_ */
