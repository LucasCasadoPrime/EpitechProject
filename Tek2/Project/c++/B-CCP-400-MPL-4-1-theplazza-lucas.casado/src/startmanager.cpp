/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** startmanager
*/

#include "../include/include.hpp"
#include "../include/Server.hpp"
#include "../include/Client.hpp"

void startManager(int nbr_cook)
{
    plazza::Server server(nbr_cook);
    server.startServer();

}

void startClient(void)
{
    plazza::Client client;
    client.init();
    client.sendData("sa");
}