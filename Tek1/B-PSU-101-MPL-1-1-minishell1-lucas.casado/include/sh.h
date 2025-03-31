/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-bsminishell1-lucas.casado
** File description:
** sh
*/

#ifndef SH_H_
#define SH_H_

#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h>
#include <sys/stat.h>

typedef struct node_s {
    void *value;
    struct node_s *next;
} node;

void out(void);
int exe(char *content, char **opt, node **env);
void push_back(node **first, void *value);
char **my_str_to_word_array(char *str, const char *separator);
int board(node **env, char **av, char *buf);
char **transform(node **env);
int my_strncmp(char *str_left, char *str_right, int count);
char *my_strcat(char *dest, char *src);
char* my_strdup(char* str);
int my_strlen(char* str);
char *my_strcpy(char *dest, char *src);
char *my_strncpy(char *dest, char *src, int n);
int my_putstr (char const *str);
void pwd(node **env, char **command);
node *search(node **head, void *value, int nb);

#endif /* !SH_H_ */
