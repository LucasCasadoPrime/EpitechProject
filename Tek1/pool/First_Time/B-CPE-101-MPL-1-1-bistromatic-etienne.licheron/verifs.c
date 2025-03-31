/*
** EPITECH PROJECT, 2020
** BistroMatic
** File description:
** simples verifications
*/

int is_a_digit(char const c, char const *base)
{
    for (int i = 0; base[i] != 0; i++) {
        if (c == base[i])
            return (1);
    }
    return (0);
}

int is_a_ops(char const c, char const *ops)
{
    for (int i = 0; ops[i] != '\0'; i++) {
        if (c == ops[i])
            return (1);
    }
    return (0);
}