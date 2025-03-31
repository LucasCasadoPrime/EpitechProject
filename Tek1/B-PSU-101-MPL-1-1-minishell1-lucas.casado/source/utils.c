/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-lucas.casado
** File description:
** utils
*/

#include "sh.h"

int my_strlen(char * str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

char *my_strdup(char *str)
{
    char *back;

	back = malloc(sizeof(*back) * (my_strlen(str) + 1));
	if (back == NULL)
		return (back);
	my_strcpy(back, str);
	return (back);
}

char *my_strcat(char *dest, char *src)
{
    int i;
    int j;

    j = 0;
    i = my_strlen(dest);
    while (src[j] != '\0') {
        dest[i] = src[j];
        i = i + 1;
        j = j + 1;
    }
    dest[i] = '\0';
    return (dest);
}

int my_strncmp(char *str_left, char *str_right, int count)
{
    while (*str_left && count > 0) {
	    if (*str_left < *str_right)
			return (-1);
		else if (*str_left > *str_right)
			return (1);
		str_left++;
		str_right++;
		count--;
	}
	if (count == 0 || (*str_left == '\0' && *str_right == '\0'))
		return (0);
	else
		return (-1);
}

char *my_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}