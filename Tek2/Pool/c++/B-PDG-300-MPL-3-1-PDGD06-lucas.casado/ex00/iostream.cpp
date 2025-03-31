/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD06-lucas.casado
** File description:
** iostream
*/

#include <iostream>
#include <fstream>

int check_error(int ac)
{
    if (ac > 2)
        return(-1);
    return(0);
}

void algo(int ac, char **as)
{
    const auto f = "my_cat: ";
    const auto ff = " no such file directory";

    for (int i = 1; i < ac; i++){
        std::ifstream file(as[i]);
        if (!file.is_open()) {
            std::cout << f << as[i] << ff << std::ends;
        } else {
            std::cout << file.rdbuf();
            file.close();
        }
    }
}

int main(int ac, char **as)
{
    const auto use = "my_cat: Usage: ./my_cat file [...]";

    if (check_error(ac) != 0)
        std::cerr << use;
    else
        algo(ac, as);
}