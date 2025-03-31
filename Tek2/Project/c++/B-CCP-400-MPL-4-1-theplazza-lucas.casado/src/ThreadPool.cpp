/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** ThreadPool
*/

#include "../include/ThreadPool.hpp"

plazza::ThreadPool::ThreadPool() {}

plazza::ThreadPool::~ThreadPool() {}


void foo() {}

void plazza::ThreadPool::pushback()
{
    std::rotate(this->_list.rbegin(), this->_list.rbegin() + 1, this->_list.rend());
}

void plazza::ThreadPool::createThread(int nbr)
{
    for (int a = 0; a < nbr; a++) {
        this->_list.push_back(new std::thread(foo));
    }
}

void plazza::ThreadPool::joinThread()
{
    for (int a = 0; a < this->_list.size(); a++)
        this->_list.at(a)->join();
}

void plazza::ThreadPool::destroy()
{
    for (int a = 0; a < this->_list.size(); a++)
        delete this->_list.at(a);
    this->joinThread();
}