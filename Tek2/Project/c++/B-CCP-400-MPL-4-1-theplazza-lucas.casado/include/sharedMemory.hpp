/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** sharedMemory
*/

#ifndef SHAREDMEMORY_HPP_
    #define SHAREDMEMORY_HPP_

    #include "include.hpp"
    #include "Commande.hpp"

namespace plazza {
    class Smemory{
        public:
            Smemory();
            ~Smemory();
            static int _shmget(key_t, size_t, int);
            static void * _shmat(int, const void *, int);
            static commandeList_t *getData(int key);
            static commandeList_t *newData(int key);
    };
}

#endif /* !SHAREDMEMORY_HPP_ */



  