/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** sharedMemory
*/

#include "../include/sharedMemory.hpp"

plazza::Smemory::Smemory() {};

plazza::Smemory::~Smemory() {};

int plazza::Smemory::_shmget(key_t __key, size_t __size, int __shmflg)
{
    return (shmget(__key, __size, __shmflg));
}

void *plazza::Smemory::_shmat(int __shmid, const void *__shmaddr, int __shmflg)
{
    return (shmat(__shmid, __shmaddr, __shmflg));
}

plazza::commandeList_t *plazza::Smemory::getData(int key)
{
    plazza::Smemory instance;
    int shmid = instance._shmget(key, sizeof(commandeList_t), 0);
    return ((commandeList_t*) instance._shmat(shmid, 0, 0));
}

plazza::commandeList_t *plazza::Smemory::newData(int key)
{
    plazza::Smemory instance;
    int shmid = instance._shmget(key, sizeof(commandeList_t), 0666 | IPC_CREAT);
    return ((commandeList_t*) instance._shmat(shmid, 0, 0));
}