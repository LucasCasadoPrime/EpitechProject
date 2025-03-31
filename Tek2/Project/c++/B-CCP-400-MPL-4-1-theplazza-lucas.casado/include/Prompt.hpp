/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** Prompt
*/

#ifndef PROMPT_HPP_
#define PROMPT_HPP_

#include "./include.hpp"
#include "./Client.hpp"
#include "./Socket.hpp"


namespace plazza {
    class Prompt {
        public:
            Prompt();
            ~Prompt();
            void Write_in_file(std::string line);
            std::vector<std::string> split(std::string phrase, std::string delimiter);
            std::vector<std::vector<std::string>> tab_manager(std::vector<std::string> tab_piza);
            std::string encryptions(std::vector<std::vector<std::string>> command, int command_count);
            std::string Command_Writer(std::string command_s, int command_count);
            std::string check_quantity(std::string command_s);
            static void start();
            plazza::Client _client;
        protected:
        private:
    };
}


#endif /* !PROMPT_HPP_ */
