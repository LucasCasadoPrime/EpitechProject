/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_
#include "include.hpp"
#include "KitchenData.hpp"
#define MAX_CONNECTION 50

namespace plazza {
    class Server {
        public:
            Server(int);
            ~Server();
            void init_sockstruct(void);
            void init(void);
            void startServer(void);
            void startKitchen(void);
            void push_save();
            const Server& operator>> (std::string&) const;
            const Server& operator<< (const std::string&) const;
            std::vector<std::string> split(std::string phrase, std::string delimiter);
        private:
            int _id;
            int _sfd;
            int _cfd;
            std::vector<KitchenData> _kitchenData;
            std::vector<std::string> _tasks;
            std::vector<int> _list;
            struct sockaddr_in _addr;
            fd_set _read_fds;
            int _nbrcook;
            bool _enable;
            std::string _cmd;
    };
}

#endif /* !SERVER_HPP_ */
