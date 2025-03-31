/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-mickael.grezes
** File description:
** quest
*/

#include "my.h"

void text_2(rpg_t *rpg)
{
    if (rpg->quest->seconds > 3.0)
        sfText_setString(rpg->quest->tfinn, "      Ganon is here !");
    if (rpg->quest->seconds > 6.0)
        sfText_setString(rpg->quest->tfinn, "  You have to kill him");
    if (rpg->quest->seconds > 9.0)
        sfText_setString(rpg->quest->tfinn, "When you'll be level five");
    if (rpg->quest->seconds > 11.0)
        sfText_setString(rpg->quest->tfinn, "        Go to castel !");
    if (rpg->quest->seconds > 13.0)
        rpg->quest->scene = 0;
}

void text(rpg_t *rpg)
{
    sfFloatRect f_rect;

    if (rpg->quest->scene == 1) {
        sfText_setPosition(rpg->quest->tfinn, (sfVector2f){970, 70});
        sfSprite_setPosition(rpg->quest->white, (sfVector2f){850, 400});
        sfText_setColor(rpg->quest->tfinn, sfBlack);
        sfText_setString(rpg->quest->tfinn, "Hi ! Link are you ready ?");
        f_rect = sfText_getGlobalBounds(rpg->quest->tfinn);
        sfText_setOrigin(rpg->quest->tfinn, \
        (sfVector2f){f_rect.width / 2, f_rect.height / 2 - 350});
        text_2(rpg);
        sfRenderWindow_drawSprite(rpg->window, rpg->quest->white, NULL);
        sfRenderWindow_drawText(rpg->window, rpg->quest->tfinn, NULL);
    }
    else
        sfClock_restart(rpg->quest->dialog);
}

void text_house(rpg_t *rpg)
{
    if (rpg->quest->scene == 2) {
        sfText_setPosition(rpg->quest->tfinn, (sfVector2f){970, 70});
        sfSprite_setPosition(rpg->quest->white, (sfVector2f){850, 400});
        sfText_setColor(rpg->quest->tfinn, sfBlack);
        sfText_setString(rpg->quest->tfinn, "I have to see Finn");
        sfFloatRect f_rect = sfText_getGlobalBounds(rpg->quest->tfinn);
        sfText_setOrigin(rpg->quest->tfinn, \
        (sfVector2f){f_rect.width / 2, f_rect.height / 2 - 350});
        if (rpg->quest->seconds2 > 2.0)
            rpg->quest->scene = 0;
        sfRenderWindow_drawSprite(rpg->window, rpg->quest->white, NULL);
        sfRenderWindow_drawText(rpg->window, rpg->quest->tfinn, NULL);
    }
    else
        sfClock_restart(rpg->quest->house);
}