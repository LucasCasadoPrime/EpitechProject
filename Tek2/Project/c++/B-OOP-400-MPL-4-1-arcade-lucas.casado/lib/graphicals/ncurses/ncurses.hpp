/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include <vector>
#include "iGraphical.hpp"
#include "Keys.hpp"

namespace arcade {
    class ncurses : public iGraphical {
        private:
            WINDOW *_window;
        public:
            ncurses();
            ~ncurses();
            void close();
            void display(std::vector<std::pair<entitiesType, entities *>> ent);
            void displaySprite(sprite *sprite);
            void erase();
            int handleKeys();
            void displayText(text_s *text);
            void displayBox();

            void init();
            std::string getName();
    };
}

#endif /* !NCURSES_HPP_ */
