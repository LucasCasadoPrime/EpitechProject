/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-etienne.licheron
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/errno.h>
#include <ctype.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>


#define MAX_CLIENT 30
#define NB_COMMAND 8

typedef struct server_s
{
    struct sockaddr_in address;
    fd_set readfds;
    char buff[1025];
    char *server_path;
    char *client_path;
    int client_socket[MAX_CLIENT];
    int valread;
    int addrlen;
    int max_sd;
    int sd;
    int current;
    int new_socket;
    int i;
    int port;
    int sockfd;
    int len_cwd;
}server_t;

int userfunc(char *buff, int client, server_t *server);
int passfunc(char *buff, int client, server_t *server);
int pwdfunc(char *buff, int client, server_t *server);
int cwdfunc(char *buff, int client, server_t *server);
int cdupfunc(char *buff, int client, server_t *server);
int quitfunc(char *buff, int client, server_t *server);
int noopfunc(char *buff, int client, server_t *server);
int deletefunc(char *buff, int client, server_t *server);

typedef struct command_s
{
    char *name;
    int(*ptr)(char *buff, int client, server_t *server);
}command_t;

char *read_fd(int fd);
void detect_ptr(server_t *server);
int add_socket(server_t *server);
int io_action(server_t *server);

#endif /* !SERVER_H_ */
