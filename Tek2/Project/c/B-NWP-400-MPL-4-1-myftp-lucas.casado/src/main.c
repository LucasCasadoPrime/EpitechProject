/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-etienne.licheron
** File description:
** main
*/

#include "../includes/server.h"

void config_server(server_t *server, char **av)
{
    server->port = atoi(av[1]);
    server->server_path = realpath(av[2], NULL);
    server->client_path = "/";
    server->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server->address.sin_addr.s_addr = htonl(INADDR_ANY);
    server->address.sin_family = AF_INET;
    server->address.sin_port = htons(server->port);
    server->addrlen = 0;
    server->max_sd = 0;
    server->sd = 0;
    server->current = 0;
    server->valread = 0;
    server->new_socket;
    bind(server->sockfd, (struct sockaddr *) \
        &server->address, sizeof(server->address));
    memset(server->client_socket, 0, \
        sizeof(int) * MAX_CLIENT);
    listen(server->sockfd, 10);
}

int multiconnect(server_t *server)
{
    server->addrlen = sizeof(server->address);
    FD_ZERO(&server->readfds);
    FD_SET(server->sockfd, &server->readfds);
    while (1) {
        FD_ZERO(&server->readfds);
        FD_SET(server->sockfd, &server->readfds);
        server->max_sd = server->sockfd;

        for (server->i = 0 ; server->i < MAX_CLIENT ; server->i++) {
            server->sd = server->client_socket[server->i];
            if (server->sd > 0)
                FD_SET(server->sd , &server->readfds);
            if (server->sd > server->max_sd)
                server->max_sd = server->sd;
        }
        server->current = select(server->max_sd + 1, \
            &server->readfds, NULL, NULL, NULL);
        if (FD_ISSET(server->sockfd, \
            &server->readfds)) {
            if ((server->new_socket = accept(server->sockfd,
                    (struct sockaddr *)&server->address, \
                    (socklen_t*)&server->addrlen)) < 0){
                perror("accept failed");
                return (84);
            }
            printf("New connection , socket fd is %d, port : %d\n", \
                server->new_socket , ntohs
                    (server->address.sin_port));
            write(server->new_socket, \
                "220 Service ready for a new user.\n", 34);
            add_socket(server);
        }
        io_action(server);
    }
}

int add_socket(server_t *server)
{
    for (server->i = 0; server->i < MAX_CLIENT; server->i++) {
        if (server->client_socket[server->i] == 0) {
            server->client_socket[server->i] = server->new_socket;
            printf("Adding to list of sockets as %d\n" , server->i);
            break;
        }
    }
    return (0);
}

int io_action(server_t *server)
{
    for (server->i = 0; server->i < MAX_CLIENT; server->i++) {
        server->sd = server->client_socket[server->i];
        if (FD_ISSET(server->sd, &server->readfds)) {;
            server->valread = read(server->sd, server->buff, 1024);
            if (server->valread == 0) {
                getpeername(server->sd , (struct sockaddr*)&server->address , \
                    (socklen_t*)&server->addrlen);
                printf("Host disconnected, port %d \n", \
                    ntohs(server->address.sin_port));
                close(server->sd);
                server->client_socket[server->i] = 0;
            } else {
                server->buff[server->valread] = '\0';
                detect_ptr(server);
            }
        }
    }
}

int main(int ac, char **av)
{
    int sock_err = 0;
    server_t server;

    config_server(&server, av);
    printf("Server: Listening on port %d ...\n", server.port);
    multiconnect(&server);
    return (0);
}
