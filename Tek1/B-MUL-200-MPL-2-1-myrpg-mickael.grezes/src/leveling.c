/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** leveling
*/

int add_xp(int to_add)
{
    static int xp = 0;

    if (to_add < 0)
        xp = 0;
    else
        xp += to_add;
    return (xp);
}

int xp_to(int level)
{
    int xp = 0;

    if (level <= 1)
        return (0);
    for (int i = 1; i < level; i++)
        xp += 75 + (i * 25);
    return (xp);
}

int actual_lvl(void)
{
    int xp = add_xp(0);
    int i = 1;

    if (xp < 100)
        return (1);
    for (; xp_to(i) <= xp; i++);
    return (i - 1);
}

int remain_xp(void)
{
    int xp = add_xp(0);
    int level = actual_lvl();

    return (xp - xp_to(level));
}

int needed_xp(void)
{
    int level = actual_lvl();

    return (xp_to(level + 1) - xp_to(level));
}