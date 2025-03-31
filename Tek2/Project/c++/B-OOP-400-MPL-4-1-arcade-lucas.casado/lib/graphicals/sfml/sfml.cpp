/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** sfml
*/

#include "sfml.hpp"
#include "Keys.hpp"
namespace arcade {
    sfml::sfml() {

    }
    sfml::~sfml() {
    }
    void sfml::erase() {
        _window.clear(sf::Color::Black);
    }
    void sfml::close() {
        _window.close();
    }
    
    void sfml::display(std::vector<std::pair<entitiesType, entities *>> ent) {
        for (auto& i : ent) {
            switch (i.first) {
                case sprite_t:
                    displaySprite((sprite *)i.second);
                    break;
                case text_t:
                    displayText((text *)i.second);
                    break;
            }
            delete(i.second);
        }
        ent.empty();
        ent.clear();
        _window.display();
    }

    void sfml::displaySprite(sprite *sprite)
    {
        sf::Sprite _sprite;
        sf::Texture _texture;
        _texture.loadFromFile(sprite->texturePath);
        _sprite.setPosition(sprite->pos.x, sprite->pos.y);
        _sprite.setTexture(_texture);
        _sprite.setScale((sf::Vector2f){sprite->scale, sprite->scale});
        _window.draw(_sprite);
    }   

    void sfml::displayText(text_s *text){
        sf::Text _text;
        sf::Font _font;
        _font.loadFromFile(text->font);
        _text.setFont(_font);
        _text.setCharacterSize(text->scale);
        _text.setFillColor(sf::Color{(sf::Uint8)text->color.r, (sf::Uint8)text->color.g, (sf::Uint8)text->color.b, (sf::Uint8)255});
        _text.setPosition((sf::Vector2f){text->pos.x, text->pos.y});
        _text.setString(text->text);
        _window.draw(_text);
    }

    void sfml::displayBox(){
    }

    int sfml::handleKeys()
    {
        _window.clear(sf::Color::Black);
        while (_window.pollEvent(_event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
                return (F1);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
                return (F2);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
                return (F5);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F6))
                return (F6);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                return (DOWN_ARROW);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                return (UP_ARROW);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                return (LEFT_ARROW);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                return (RIGHT_ARROW);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                return (RETURN);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                return (ESCAPE);
            return (-1);
        }
        return 0;
    }
    
    void sfml::init() {
        _window.create(sf::VideoMode(1080, 720), "Arcade", sf::Style::Default);
        _window.setFramerateLimit(30);
        _window.setMouseCursorVisible(false);
    };
    
    std::string sfml::getName() {
        return "SFML";
    }
}

extern "C" arcade::sfml* getGraphical() {
    return (new arcade::sfml());
}