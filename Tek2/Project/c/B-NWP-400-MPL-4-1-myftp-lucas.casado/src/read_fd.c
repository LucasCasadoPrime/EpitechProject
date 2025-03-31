/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-lucas.casado
** File description:
** command
*/

#include "../includes/server.h"

command_t command[NB_COMMAND] = {
    {"USER", userfunc},
    {"PASS", passfunc},
    {"PWD", pwdfunc},
    {"CWD", cwdfunc},
    {"CDUP", cdupfunc},
    {"QUIT", quitfunc},
    {"NOOP", noopfunc},
    {"DELE", deletefunc},

};

void detect_ptr(server_t *server)
{
    int count = 0;
    int max = 0;
    size_t size;
    for (int i = 0; i < NB_COMMAND; i++) {
        max = strlen(command[i].name);
        if (strncmp(command[i].name, server->buff, max) == 0 ) {
            command[i].ptr(server->buff, server->sd, server);
            count++;
            break;
        }
    }
    for (int i = 0; i < strlen(server->buff); i++) {
        if (!isspace(server->buff[i]))
            count += 1;
    }
    if (count == 0)
        dprintf(server->sd, "500\r\n");
}

int deletefunc(char *buff, int client, server_t *server)
{
    char *dele;
    char *tmp;
    FILE *file;

    tmp = strdup(server->server_path);
    dele = strtok(buff, " ");
    if (strcmp(dele, "DELE") == 0) {
        dele = strtok(NULL, " ");
    }
    if (dele[0] == 13)
        write(client, "xxx\r\n", 5);
    else {
        dele[strlen(dele)-1] = '\0';
        strcat(tmp, "/");
        strcat(tmp, dele);
        printf("%s\r\n", dele);
        file = fopen(tmp, "r");
        if (file){
            fclose(file);
            remove(tmp);
            dprintf(client, "250 file removed\r\n");
        } else {
            dprintf(client, "550 No such file\r\n");
        }
    }
}

int noopfunc(char *buff, int client, server_t *server)
{
    write(client, "200 Requested action completed successfully.\r\n", 46);
}

int quitfunc(char *buff, int client, server_t *server)
{

    dprintf(client, "221\r\n");
    close(client);
    FD_CLR(client, &server->readfds);
    client = 0;
}
