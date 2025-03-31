/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** Socket
*/

#ifndef SOCKET_HPP_
#define SOCKET_HPP_
#include "include.hpp"

namespace plazza {
    class Socket {
        public:
            Socket();
            ~Socket();
            static int createSocket(int, int, int);
            static int bindServer(int, const sockaddr *, socklen_t);
            static int acceptConnexion(int, sockaddr *__restrict__, socklen_t *__restrict__);
            static int selectFD(int, fd_set *__restrict__, fd_set *__restrict__, fd_set *__restrict__, struct timeval *__restrict__);
            static int listenFD(int, int);
            static int writeFD(int fd, std::string);
            static int myConnect(int __fd, sockaddr *__addr, socklen_t __len);
            static ssize_t myRecv(int __fd, void *__buf, size_t __n, int __flags);
            static ssize_t mySend(int, const void *, size_t, int);
            static pid_t myFork(void);
            static void myExit(int);
        protected:
        private:
    };
}

#endif /* !SOCKET_HPP_ */
