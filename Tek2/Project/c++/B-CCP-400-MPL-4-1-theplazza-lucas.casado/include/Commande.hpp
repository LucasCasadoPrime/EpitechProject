/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** Commande
*/

#ifndef COMMANDE_HPP_
#define COMMANDE_HPP_

#include "include.hpp"


namespace plazza {

    typedef struct commandeList_s {
        int _var;
    }commandeList_t;

    class Commande {
        public:
            Commande(std::string);
            ~Commande();
            std::vector<std::string> _var;
            int _num;
            int _type;
            int _size;
            int _quantity;
        protected:
        private:
    };
}

#endif /* !COMMANDE_HPP_ */
