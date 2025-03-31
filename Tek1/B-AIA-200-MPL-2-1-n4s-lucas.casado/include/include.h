/*
** EPITECH PROJECT, 2021
** B-AIA-200-MPL-2-1-n4s-lucas.casado
** File description:
** include
*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define EXIT_FAIL (84)
#define EXIT_OK (0)
#define SPEED_POS (15)
#define DIRECTION_POS (15)
#define COMMAND_LIMIT_SIZE (250)
#define GET_INFO_COMMAND ("get_info_lidar\n")
#define START_SIMULATION ("start_simulation\n")
#define STOP_SIMULATION ("stop_simulation\n")
#define END_COMMAND ("Track Cleared")

int exe(const char *command);
void my_put_str(const char *str);
void my_put_char(char c);
int my_strlen(const char *str);
int end_run(char *str);
char *lread(void);
char *manage_str(char *str);
int speed(void);
int dir(void);
void drive(void);
char **my_str_to_word_array(char *str, const char *separator);
int my_strlen(const char *str);
void my_put_str(const char *str);
void my_put_char(char c);
int my_put_float(double nbr);
double my_atof(char *str);
int my_strcmp(const char *s1, const char *s2);

#endif /* !INCLUDE_H_ */
