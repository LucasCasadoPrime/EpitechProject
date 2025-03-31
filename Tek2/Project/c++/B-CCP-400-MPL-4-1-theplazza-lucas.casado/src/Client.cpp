/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** Client
*/

#include "../include/Client.hpp"
#include "../include/Socket.hpp"
#include "../include/Error.hpp"

plazza::Client::Client() 
{
    this->init();
    this->_started = false;
}

plazza::Client::~Client() {}

void plazza::Client::init() 
{
    this->initStruct();
    this->_fdc = plazza::Socket::createSocket(AF_INET, SOCK_STREAM, 0);
}

void plazza::Client::initStruct()
{
    this->_hints.sin_family  = AF_INET;
    this->_hints.sin_addr.s_addr = inet_addr("127.0.0.1");
    this->_hints.sin_port = htons(8000);
}

void plazza::Client::startClient(void)
{
    this->_connection = plazza::Socket::myConnect(this->_fdc, reinterpret_cast<struct sockaddr *>(&this->_hints), sizeof(this->_hints));
    if (this->_connection == -1)
        std::cout << "[Client] : error during connection" << std::endl;
    else
        this->_started = true;
}

std::string plazza::Client::sendData(std::string str)
{
    // memset(this->_buff, 0, 200);
    if (this->_started == false) {
        this->startClient();
    }
    plazza::Socket::mySend(this->_fdc, str.c_str(), str.size(), 0);
    std::cout << "[Client] : send " << str << std::endl;
        // if(plazza::Socket::myRecv(this->_fdc, this->_buff, 200, 0));
    // str = this->_buff;
    return (str);
}