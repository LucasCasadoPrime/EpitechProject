/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Config.hpp>
#include <SFML/OpenGL.hpp>
#include "iGraphical.hpp"
#include "Keys.hpp"
#include <vector>

namespace arcade {
    class sfml : public iGraphical {
        private:
            sf::RenderWindow _window;
            sf::Event _event;
        public:
            sfml();
            ~sfml();
            void close();
            void display(std::vector<std::pair<entitiesType, entities *>> ent);
            void displaySprite(sprite *sprite);
            void erase();
            void displayBox();
            int handleKeys();
            void displayText(text_s *text);
            void init();
            std::string getName();
    };
}
#endif /* !SFML_HPP_ */
