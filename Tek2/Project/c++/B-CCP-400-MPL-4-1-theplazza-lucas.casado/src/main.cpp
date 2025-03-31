/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-panoramix-lucas.casado
** File description:
** main
*/

#include "../include/include.hpp"
#include "../include/GetParams.hpp"
#include "../include/Prompt.hpp"
#include "../include/Error.hpp"
#include "../include/Kitchen.hpp"
#include "../include/Server.hpp"

void start(int val)
{
    plazza::Server server(val);
    server.startServer();

    // plazza::Kitchen kitechen(val);

    // for (;;) {
    //     kitechen.getData();
    // }
}

int main(int argc, char **argv)
{
    try {
        plazza::GetParams param(argc, argv);
        std::thread manager(start, param.nbCooks);
        plazza::Prompt::start();
        manager.join();
    } catch (plazza::Error &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
}
