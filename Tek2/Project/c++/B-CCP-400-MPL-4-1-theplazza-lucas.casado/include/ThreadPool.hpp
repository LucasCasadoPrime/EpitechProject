/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** ThreadPool
*/

#ifndef THREADPOOL_HPP_
#define THREADPOOL_HPP_

#include "include.hpp"

namespace plazza {
    class ThreadPool {
        public:
            ThreadPool();
            ~ThreadPool();
            void createThread(int);
            void pushback(void);
            void joinThread(void);
            void destroy(void);
        protected:
        private:
            std::vector<std::thread*> _list;
    };
}

#endif /* !THREADPOOL_HPP_ */
