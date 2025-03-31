/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-lucas.casado
** File description:
** command
*/

#include "../includes/server.h"

static int verify = 0;

int userfunc(char *buff, int client, server_t *server)
{
    char *log;
    (void) server;

    log = strtok(buff, " ");
    if (strcmp(log, "USER") == 0){
        log = strtok(NULL, " ");
    }
    if (log[0] == 13)
        write(client, "xxx\n", 4);
    else if (log[0] == 85)
        write(client, "xxx\n", 4);
    else if (strncmp(log, "Anonymous", 9) == 0) {
        write(client, "331 User name okay, need password.\r\n", 36);
        verify += 1;
    }
    else if (strncmp(log, "Ano", 3) == 0) {
        dprintf(client, "220\r\n");
        verify += 1;
    } else {
        write(client, "331 User name okay, need password.\r\n", 36);
        verify += 1;
    }
    return (0);
}

int passfunc(char *buff, int client, server_t *server)
{
    char *psw;
    (void) server;

    psw = strtok(buff, " ");
    if (verify == 0)
        write(client, "332 User need USER to login.\r\n", 30);
    else {
        if (strcmp(psw, "PASS") == 0) {
            psw = strtok(NULL, " ");
            write(client, "230 User logged in, proceed.\r\n", 30);
        }
    }
    return (0);
}

int pwdfunc(char *buff, int client, server_t *server)
{
    dprintf(client, "257 %s\r\n", server->client_path);
}

int cwdfunc(char *buff, int client, server_t *server)
{
    char *cwd;
    char *tmp;
    int len = 0;
    struct stat st;

    tmp = strdup(server->server_path);
    cwd = strtok(buff, " ");
    if (strcmp(cwd, "CWD") == 0) {
        cwd = strtok(NULL, " ");
    }
    if (cwd[0] == 13)
        write(client, "xxx\r\n", 5);
    else {
        cwd[strlen(cwd)-1] = '\0';
        server->len_cwd = strlen(cwd);
        strcat(tmp, "/");
        strcat(tmp, cwd);
        DIR *dir = opendir(tmp);
        if (ENOENT == errno) {
            dprintf(client, "550 No such directory\r\n");
        } else {
            closedir(dir);
            strcat(server->server_path, "/");
            strcat(server->server_path, cwd);
            server->client_path = malloc(sizeof(char) \
                * strlen(server->server_path) + strlen(cwd) + 1);
            server-> client_path[strlen(server->client_path) \
                + strlen(cwd) + 1] = '\0';
            server->client_path[0] = '/';
            strcat(cwd, "/");
            strcat(server->client_path, cwd);
            dprintf(client, "250\r\n");
        }

    }
}

int cdupfunc(char *buff, int client, server_t *server)
{
    server->server_path[strlen(server->server_path) - server->len_cwd-1] = '\0';
    server->client_path[strlen(server->client_path) - server->len_cwd-1] = '\0';
    write(client, "200 Requested action completed successfully.\r\n", 46);
}
