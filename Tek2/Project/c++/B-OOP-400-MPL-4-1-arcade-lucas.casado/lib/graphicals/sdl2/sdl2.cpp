/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** sfml
*/

#include "sdl2.hpp"

namespace arcade {
    sdl2::sdl2() {}
    sdl2::~sdl2() {}
    void sdl2::erase()
    {
        SDL_RenderPresent(_renderer);
        SDL_RenderClear(_renderer);
    }

    void sdl2::close()
    {
        SDL_DestroyWindow(_window);
        SDL_Quit();
    }

    int sdl2::handleKeys()
    {
        if (SDL_PollEvent(&_event) != 0) {
            if (_event.type == SDL_KEYDOWN) {
                switch(_event.key.keysym.sym) {
                case SDLK_RIGHT :
                    return (RIGHT_ARROW);
                case SDLK_LEFT :
                    return (LEFT_ARROW);
                case SDLK_UP :
                    return (UP_ARROW);
                case SDLK_DOWN :
                    return (DOWN_ARROW);
                case SDLK_F1 :
                    return (F1);
                case SDLK_F2 :
                    return (F2);
                case SDLK_F5 :
                    return (F5);
                case SDLK_F6 :
                    return (F6);
                case SDLK_ESCAPE :
                    return (ESCAPE);
                case SDLK_RETURN :
                    return (RETURN);

                }
            }
        }
        
        return 0;
    }

    void sdl2::display(std::vector<std::pair<entitiesType, entities *>> ent) {
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
    }

    void sdl2::displaySprite(sprite *sprite)
    {
        int texW = 10;
        int texH = 10;
        SDL_Surface *surface = IMG_Load(sprite->texturePath.c_str());
        SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer,surface);
        SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
        SDL_Rect dstrect = { (int)sprite->pos.x, (int)sprite->pos.y, texW, texH };
        SDL_RenderCopy(_renderer, texture, NULL, &dstrect);
        SDL_DestroyTexture(texture);
    }


    void sdl2::displayText(text_s *text)
    {
        SDL_Color color;
        int texW = 100;
        int texH = 100;

        color.r = text->color.r;
        color.g = text->color.g;
        color.b = text->color.b;
        color.a = 255;

        _font = TTF_OpenFont(text->font.c_str(), text->scale);
        SDL_Surface* surface = TTF_RenderText_Blended(_font, text->text.c_str(), color);
        TTF_CloseFont(_font);
        SDL_Texture * texture = SDL_CreateTextureFromSurface(_renderer,surface);
        SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
        SDL_Rect dstrect = { (int)text->pos.x, (int)text->pos.y-20, texW, texH };
        SDL_RenderCopy(_renderer, texture, NULL, &dstrect);
    }


    void sdl2::displayBox(){}
    
    void sdl2::init() 
    {
        SDL_Init(SDL_INIT_VIDEO);
        _window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1080, 720, SDL_WINDOW_SHOWN);
        TTF_Init();
        _renderer = SDL_CreateRenderer(_window, -1, 0);
    }

    std::string sdl2::getName()
    {
        return "SDL2";
    };
}

extern "C" arcade::sdl2* getGraphical() {
    return (new arcade::sdl2());
}