/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** Server
*/

#include "../include/Server.hpp"
#include "../include/Socket.hpp"
#include "../include/Error.hpp"
#include "../include/Kitchen.hpp"
#include "../include/Prompt.hpp"

std::vector<std::string> plazza::Server::split(std::string phrase, std::string delimiter)
{
    std::vector<std::string> list;
    size_t pos = 0;
    std::string token;
    while ((pos = phrase.find(delimiter)) != std::string::npos) {
        token = phrase.substr(0, pos);
        list.push_back(token);
        phrase.erase(0, pos + delimiter.length());
    }
    list.push_back(phrase);
    return list;
}

plazza::Server::Server(int nbr) 
{
    try {
        this->_enable = true;
        this->_nbrcook = nbr;
        this->init();
    } catch (plazza::Error &e) {
        std::cerr << e.what() << std::endl;
        close(this->_sfd);
        this->_enable = false;
    }
}

plazza::Server::~Server() 
{
    close(this->_sfd);
}

void plazza::Server::init()
{
    this->init_sockstruct();
    this->_list.clear();
    this->_sfd = plazza::Socket::createSocket(AF_INET, SOCK_STREAM, 0);

    int ret = plazza::Socket::bindServer(this->_sfd, reinterpret_cast<struct sockaddr *> (&(this->_addr)), sizeof(this->_addr));
    if (ret == -1) {
        close(this->_sfd);
        throw plazza::Error("[Server] : Error durring bind");
    }
    ret =  plazza::Socket::listenFD(this->_sfd, MAX_CONNECTION);
    if (ret == -1) {
        close(this->_sfd);
        throw plazza::Error("[Server] : Error durring listen");
    }
}

void plazza::Server::init_sockstruct(void)
{
    this->_addr.sin_family = AF_INET;
    this->_addr.sin_addr.s_addr = INADDR_ANY;
    this->_addr.sin_port = htons(8000);
}

const plazza::Server& plazza::Server::operator<< (const std::string &s) const 
{
    plazza::Socket::mySend(this->_cfd, s.c_str(), s.size(), MSG_NOSIGNAL); 

    return (*this);
}

const plazza::Server& plazza::Server::operator>> (std::string &s) const 
{
    int len = 200;
    char buff[len];
    memset(buff, 0, len);

    plazza::Socket::myRecv(this->_cfd, buff, len, 0);
    s = buff;
    return (*this);
}

void plazza::Server::startKitchen(void)
{
    if (plazza::Socket::myFork() == 0) {
        plazza::Kitchen Kitchen(this->_nbrcook, this->_id);
        exit(0);
    }
    this->_id += 1;
}

void plazza::Server::push_save(void)
{
    KitchenData data(this->_id);
    this->_kitchenData.push_back(data);
}

void plazza::Server::startServer()
{

    if (this->_enable == false)
        return;
    socklen_t len = sizeof(struct sockaddr_in);
    std::string data;
     std::vector<std::string> tab;
    fd_set rfds;

    for (;;) {
        FD_ZERO(&rfds);
        FD_SET(this->_sfd, &rfds);
        
        for (int a = 0; a < this->_list.size(); a++) {
            FD_SET(this->_list.at(a), &rfds);
        }
        if (this->_tasks.size() != 0) {
            this->startKitchen();
            this->push_save();
        }
        plazza::Socket::selectFD(50, &rfds, NULL, NULL, 0);

        if (FD_ISSET(this->_sfd, &rfds)) {
            this->_list.push_back(plazza::Socket::acceptConnexion(this->_sfd, reinterpret_cast<struct sockaddr *> (&(this->_addr)), &len));
        }
        for (int a = 0; this->_list.size() > a; a++) {
            if (FD_ISSET(this->_list.at(a), &rfds)) {
                this->_cfd = this->_list.at(a);
                *this >> data;
                std::cout << "Server [GetData] : " << data << std::endl;
                if (data == "status") {
                    std::cout << "###############################################################" << std::endl;
                    std::cout << "#                        Kitchen Status                       #" << std::endl;
                    std::cout << "###############################################################" << std::endl;
                    if (this->_kitchenData.size() == 0)
                        std::cout << "No kitchen have been start" << std::endl;
                    for (int a = 0; a < this->_kitchenData.size(); a++)
                        this->_kitchenData.at(a).printInfo();
                }
                else if (data == "exit") {
                    close (this->_sfd);
                    plazza::Socket::myExit(0);
                }
                else {
                    std::cout << "Server [SendData] : " << data << std::endl;
                    if (isdigit(data[0] == true)) {
                        std::cout << "kitchen" << std::endl;
                    }
                    if (isalpha(data[0] == true)) {
                        tab = this->split(data,":");
                        for (int i = 1; i < tab.size(); i++) {
                            this->_tasks.push_back(tab[i]);
                        }
                    }
                }
            }
        }
    }
}
