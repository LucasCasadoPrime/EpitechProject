/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** Socket
*/

#include "../include/Socket.hpp"

plazza::Socket::Socket() {}

plazza::Socket::~Socket() {}

int plazza::Socket::createSocket(int domain, int type, int protocole)
{
    return (socket(domain, type, protocole));
}

int plazza::Socket::bindServer(int __fd, const sockaddr *__addr, socklen_t __len)
{
    return (bind(__fd, __addr, __len));
}

int plazza::Socket::acceptConnexion(int __fd, sockaddr *__restrict__ __addr, socklen_t *__restrict__ __addr_len)
{
    return (accept(__fd, __addr, __addr_len));
}

int plazza::Socket::selectFD(int __nfds, fd_set *__restrict__ __readfds, fd_set *__restrict__ __writefds, fd_set *__restrict__ __exceptfds, struct timeval *__restrict__ __timeout)
{
    return (select(__nfds, __readfds, __writefds, __exceptfds, __timeout));
}

int plazza::Socket::listenFD(int __fd, int __n)
{
    return (listen(__fd, __n));
}

int plazza::Socket::writeFD(int fd, std::string str)
{
    return (write(fd, str.c_str(), str.length()));
}

int plazza::Socket::myConnect(int __fd, sockaddr *__addr, socklen_t __len)
{
    return (connect(__fd, __addr, __len));
}

ssize_t plazza::Socket::myRecv(int __fd, void *__buf, size_t __n, int __flags)
{
    return (recv(__fd, __buf, __n, __flags));
}

ssize_t plazza::Socket::mySend(int __fd, const void *__buf, size_t __n, int __flags)
{
    return(send(__fd, __buf, __n, __flags));
}

pid_t plazza::Socket::myFork()
{
    return(fork());
}

void plazza::Socket::myExit(int __status)
{
    return (exit(__status));
}