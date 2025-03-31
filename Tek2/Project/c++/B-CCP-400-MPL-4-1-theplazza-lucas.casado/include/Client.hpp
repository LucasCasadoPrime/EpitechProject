/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_
#include "include.hpp"

namespace plazza {
    class Client {
        public:
            Client();
            ~Client();
            void init(void);
            void initStruct(void);
            void startClient(void);
            std::string sendData(std::string str);
        protected:
        private:
            bool _started;
            sockaddr_in _hints;
            int _address;
            int _fdc;
            int _connection;
            char _buff[200];
    };
}

#endif /* !CLIENT_HPP_ */
