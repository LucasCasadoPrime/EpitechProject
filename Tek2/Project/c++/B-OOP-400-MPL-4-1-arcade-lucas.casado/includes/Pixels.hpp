/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** pixels
*/

#ifndef PIXELS_HPP_
#define PIXELS_HPP_

#include <string>

typedef enum {
    NO = -1,
    UP,
    DOWN,
    LEFT,
    RIGHT,
} Direction;

class Pixel {
    public:
        Pixel() {
            this->_x = 0;
            this->_y = 0;
            this->_sprite = "";
            this->_symbol = "";
        };

        Pixel(unsigned int x, unsigned int y, std::string sprite, std::string symbol) {
            this->_x = x;
            this->_y = y;
            this->_sprite = sprite;
            this->_symbol = symbol;
        };

        ~Pixel() {};
        Pixel(const Pixel&) = default;
        Pixel(Pixel&&) = default;

        Pixel operator=(Pixel const &ot)
        {
            return (Pixel(ot._x, ot._y, ot._sprite, ot._symbol));
        }

        /* set new position x and y */
        void setPosition(unsigned int x, unsigned int y)
        {
            this->_x = x;
            this->_y = y;
        };

        /* Set path of the sprite texture*/
        void setSprite(std::string sprite)
        {
            this->_sprite = sprite;
        };

        /* Set symbol of the sprite texture*/
        void setSymbol(std::string symbol)
        {
            this->_symbol = symbol;
        };

        /* Current position x*/
        unsigned int _x;
        /* Current position y*/
        unsigned int _y;

        /* Path of the sprite texture*/
        std::string _sprite;

        /* Symbol of the sprite texture*/
        std::string _symbol;
};

#endif /* !PIXELS_HPP_ */
