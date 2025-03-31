/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** open_file
*/

#include "my.h"

char *open_file(char *filename)
{
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    ssize_t line_size;
    FILE *fp = fopen(filename, "r");
    char *content = NULL;

    if (!fp)
        return (NULL);
    line_size = getline(&line_buf, &line_buf_size, fp);
    content = malloc(20000);
    content[0] = 0;
    for (; line_size >= 0; line_size = getline(&line_buf, &line_buf_size, fp))
        my_strcat(content, line_buf);
    fclose(fp);
    free(line_buf);
    return (content);
}