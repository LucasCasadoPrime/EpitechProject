/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** nibbler
*/

#include "nibbler.hpp"

int fruit_count;
int last_position_xi;
int last_position_yi;
int direction_stk;

namespace arcade {
    nibbler::nibbler() {}

    nibbler::~nibbler() {}

    void nibbler::init() {}

    std::string nibbler::getName() {return "Nibbler";}

    std::vector<std::pair<entitiesType, entities *>> nibbler::runtime(int key, int &_game, bool &_running) {
        std::vector<std::pair<entitiesType, entities *>> ent;
        static float x = 230;
        static float y = 150;
        int index = 0;
        // int fruit_count;
        static int direction = 0;
        static int size_snake = 3;
        std::vector<char>c;
        char cha;
        char *string;
        std::fstream myfile ("assets/nibbler/map.txt");
        std::vector<std::vector<char>> map;
        map.push_back(std::vector<char>());
        if (myfile.is_open()) {
            while (myfile.get(cha)){c.push_back(cha);}
            for (const auto &i : c) {
                if (i == '0') {
                    map[index].push_back(i);
                    sprite *floor = new sprite();
                    floor->texturePath = "assets/nibbler/floor.png";
                    floor->scale = 1;
                    floor->symbol = ' ';
                    floor->pos = {x, y};
                    ent.push_back(std::pair<entitiesType, entities*>(sprite_t, floor));
                    x += 16;
                }
                if (i == 'B') {
                    map[index].push_back(i);
                    sprite *body = new sprite();
                    body->texturePath = "assets/nibbler/body.png";
                    body->scale = 1;
                    body->symbol = ' ';
                    body->pos = {x, y};
                    ent.push_back(std::pair<entitiesType, entities*>(sprite_t, body));
                    x += 16;
                }
                if (i == 'F') {
                    map[index].push_back(i);
                    sprite *fruit = new sprite();
                    fruit->texturePath = "assets/nibbler/fruit.png";
                    fruit->scale = 1;
                    fruit->symbol = '*';
                    fruit->pos = {x, y};
                    ent.push_back(std::pair<entitiesType, entities*>(sprite_t, fruit));
                    x += 16;
                }
                if (i == '\n') {
                    map[index].push_back(i);
                    map.push_back(std::vector<char>());
                    index += 1;
                    y += 16;
                    x = 230;
                }
                if (i == '1') {
                    map[index].push_back(i);
                    sprite *background = new sprite();
                    background->texturePath = "assets/nibbler/block.png";
                    background->scale = 1;
                    background->symbol = 'X';
                    background->pos = {x, y};
                    x += 16;
                    ent.push_back(std::pair<entitiesType, entities*>(sprite_t, background));
                }
                if (i == 'P') {
                    map[index].push_back(i);
                    sprite *player = new sprite();
                    player->texturePath = "assets/nibbler/snake.png";
                    player->scale = 1;
                    player->symbol = 'C';
                    player->pos = {x, y};
                    ent.push_back(std::pair<entitiesType, entities*>(sprite_t, player));
                    x += 16;
                }
            }
        }
        if (key == RIGHT_ARROW)
            direction = 0;
        if (key == DOWN_ARROW)
            direction = 1;
        if (key == LEFT_ARROW)
            direction = 2;
        if (key == UP_ARROW)
            direction = 3;
        for (int xi = 0; xi < (int)map.size(); xi += 1) {
            for (int yi = 0; yi < (int)map[xi].size(); yi += 1) {
                if (map[xi][yi] == 'P') {
                    if (direction == 0 && map[xi][yi + 1] == '0') {
                        if (direction == 1) {
                            map[last_position_xi][last_position_yi/*- la zone a effacer*/] = '0';
                        }
                        map[xi][yi + 1] = 'P';
                        //ajouter le fruit count dans une boucle while pour generer la queue si on a manger + d'un fruit
                        if (fruit_count >= 1) {
                            map[xi][yi] = 'B';
                            map[xi][yi - 1] = '0';
                        } else {
                            map[xi][yi] = '0';
                        }
                        last_position_xi = xi;
                        last_position_yi = yi;
                        direction_stk  = direction;
                        break;
                    }
                    else if (direction == 1 && map[xi + 1][yi] == '0') {
                        map[xi + 1][yi] = 'P';
                        // printf("%d\  n", last_position_xi);
                        if (fruit_count >= 1) {
                            map[xi][yi] = 'B';
                            map[xi - 1][yi] = '0';
                        } else {
                            map[xi][yi] = '0';
                        }
                        last_position_xi = xi;
                        last_position_yi = yi;
                        direction_stk  = direction;
                        break;
                    }
                    else if (direction == 2 && map[xi][yi - 1] == '0') {
                        map[xi][yi - 1] = 'P';
                        if (fruit_count >= 1) {
                            map[xi][yi] = 'B';
                            map[xi][yi + 1] = '0';
                        } else {
                            map[xi][yi] = '0';
                        }
                        last_position_xi = xi;
                        last_position_yi = yi;
                        direction_stk  = direction;
                        break;
                    }
                    if (direction == 3 && map[xi - 1][yi] == '0') {
                        printf("%d\n", last_position_xi);
                        map[xi - 1][yi] = 'P';
                        // printf("les fruit %d\n ", fruit_count);
                        if (fruit_count >= 1) {
                            map[xi][yi] = 'B'; 
                            map[xi + 1][yi] = '0';
                        } else {
                            map[xi][yi] = '0';
                        }
                        last_position_xi = xi;
                        last_position_yi = yi;
                        direction_stk  = direction;
                        break;
                    }
                    // collisions loose
                    if (direction == 0 && map[xi][yi + 1] == '1' || direction == 1 && map[xi + 1][yi] == '1' || direction == 2 && map[xi][yi - 1] == '1' || direction == 3 && map[xi - 1][yi] == '1') {
                        text *gameover = new text();
                        gameover->scale = 45;
                        gameover->color = {255, 0, 0};
                        gameover->font = "assets/menu/font.otf";
                        gameover->pos = {430, 300};
                        gameover->text = "GAME OVER";
                        ent.push_back(std::pair<entitiesType, entities*>(text_t, gameover));
                        break;
                    }
                }
            }
            
        }
        for (int xi = 0; xi < (int)map.size(); xi += 1) {
            for (int yi = 0; yi < (int)map[xi].size(); yi += 1) {
                if (map[xi][yi] == 'P') {
                    if (direction == 0 && map[xi][yi + 1] == 'F') {
                        map[xi][yi + 1] = 'P';
                        map[xi][yi] = 'B';
                        map[xi][yi - 1] = 'F';
                        fruit_count = fruit_count + 1;
                         printf("%d\n ", fruit_count);
                        break;
                    }
                    else if (direction == 1 && map[xi + 1][yi] == 'F') {
                        map[xi + 1][yi] = 'P';
                        map[xi][yi] = 'B';
                        map[xi -1][yi] = 'F';
                        fruit_count = fruit_count + 1;
                        printf("%d\n ", fruit_count);
                        xi += 1;
                        break;
                    }
                    else if (direction == 2 && map[xi][yi - 1] == 'F') {
                        map[xi][yi - 1] = 'P';
                        map[xi][yi] = 'B';
                        map[xi][yi + 1] = 'F';
                        fruit_count = fruit_count + 1;
                         printf("%d\n ", fruit_count);
                        break;
                    }
                    if (direction == 3 && map[xi - 1][yi] == 'F') {
                        map[xi - 1][yi] = 'P'; 
                        map[xi][yi] = 'B';
                        map[xi + 1][yi] = 'F';
                        fruit_count = fruit_count + 1;
                         printf("%d\n ", fruit_count);
                        break;
                    }
                }
            }
            
        }
        myfile.close();
        myfile.open("assets/nibbler/map.txt", std::fstream::out);
        for (int xi = 0; xi < (int)map.size(); xi += 1) {
            for (int yi = 0; yi < (int)map[xi].size(); yi += 1) {
                myfile << map[xi][yi];
            }
        }
        myfile.close();
        x = 230;
        y = 150;
        text *title = new text();
        title->scale = 45;
        title->color = {169, 77, 255};
        title->font = "assets/menu/font.otf";
        title->pos = {0, 10};
        title->text = "NIBBLER";
        ent.push_back(std::pair<entitiesType, entities*>(text_t, title));
        return (ent);
    }
}

extern "C" arcade::nibbler* getGame() {
    return (new arcade::nibbler());
}