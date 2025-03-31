/*
** EPITECH PROJECT, 2022
** C++
** File description:
** sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Graphics.hpp>

class sfml 
{
    public:
        sfml();
        ~sfml();
        virtual void mainWindow();
        void initWindow();
        void handleEvents();
        void all_element();
        sf::RenderWindow *getWindow() const;
        sf::Event *getEvent() const;
    private:
        sf::RenderWindow *_window;
        sf::Event *_event;
};

#endif /* !SFML_HPP_ */
