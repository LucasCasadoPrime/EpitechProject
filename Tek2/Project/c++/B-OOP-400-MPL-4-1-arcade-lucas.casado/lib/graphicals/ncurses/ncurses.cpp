/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** sfml
*/

#include "ncurses.hpp"
#include <iostream>
#include <unistd.h>

namespace arcade {
    ncurses::ncurses() {}
    ncurses::~ncurses() {}

    void ncurses::erase()
    {
        usleep(100000);
        clear();
    }
    
    void ncurses::close()
    {
        endwin();
    }

    int ncurses::handleKeys() {
        int ch = getch();
    
        if (ch == KEY_F(1))
            return (F1);
        if (ch == KEY_F(2))
            return (F2);
        if (ch == KEY_F(5)) {
            clear();
            refresh();
            return (F5);
        }
        if (ch == KEY_F(6)) {
            clear();
            refresh();
            return (F6);
        }
        if (ch == 27)
            return (ESCAPE);
        if (ch == KEY_DOWN) {
            clear();
            refresh();
            return (DOWN_ARROW);
        }
        if (ch == KEY_UP) {
            clear();
            refresh();
            return (UP_ARROW);
        }
        if (ch == KEY_LEFT) {
            clear();
            refresh();
            return (LEFT_ARROW);
        }
        if (ch == KEY_RIGHT) {
            clear();
            refresh();
            return (RIGHT_ARROW);
        }
        if (ch == KEY_ENTER)
            return (RETURN);
        return (-1);
    }

    void ncurses::display(std::vector<std::pair<entitiesType, entities *>> ent) {
        for (auto& i : ent) {
            switch (i.first) {
                case sprite_t:;
                    displaySprite((sprite *)i.second);
                    break;
                case text_t:
                    displayText((text *)i.second);
                    break;
            }
        }
        ent.empty();
        ent.clear();
        refresh();
    }

    void ncurses::displaySprite(sprite *sprite)
    {
        if (sprite->symbol == ' ')
            return;
        std::string s(1, sprite->symbol);
        mvprintw(sprite->pos.y/30, sprite->pos.x/30, s.c_str());
    }

    void ncurses::displayText(text_s *text)
    {
        mvprintw(text->pos.y/30, text->pos.x/30, text->text.c_str());
    }
    void ncurses::displayBox(){}

    void ncurses::init() {
        _window = initscr();
        noecho();
        keypad(stdscr, TRUE);
        nodelay(stdscr, true);
    }
    std::string ncurses::getName() {return "Ncurses";}
}

extern "C" arcade::ncurses* getGraphical() {
    return (new arcade::ncurses());
}